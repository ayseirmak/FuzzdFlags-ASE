#!/usr/bin/env python3
import subprocess
import shlex
import pandas as pd
import time
from pathlib import Path

def diff_any_nuniq(row, keys):
    cols = [f"{k}_{c}" for k in keys for c in ("clang-17","clang-19","clang-22")]
    # nunique(dropna=True) drops NaNs automatically
    return row[cols].nunique(dropna=True) > 1

def stdout_diff(row):
    outs = [row[f"exec_stdout_hash_{c}"] for c in ("clang-17", "clang-19", "clang-22")]
    # treat NaN and empty string the same; strip trailing whitespace
    outs_norm = [str(o).strip() if pd.notna(o) else "" for o in outs]
    return len(set(outs_norm)) > 1
  
df = pd.read_csv('/users/user42/difftest/seed_results_1000000_hash.csv')
wide = (
    df
    .pivot_table(index=['program', 'flags'],   # each test case
                 columns='compiler',           # clang‑17 / 19 / 22
                 values=['compile_rc', 'exec_rc', 'exec_stdout_hash', 'exec_stderr_hash'],
                 aggfunc='first')
)

# make the MultiIndex easier to read
wide.columns = ['_'.join(col) for col in wide.columns]
wide['compile_mismatch'] = wide.apply(lambda r: diff_any_nuniq(r, ['compile_rc']), axis=1)
wide['exec_mismatch']    = wide.apply(lambda r: diff_any_nuniq(r, ['exec_rc']),    axis=1)
wide['output_mismatch']  = wide.apply(stdout_diff, axis=1)

inconsistent = wide.query('compile_mismatch or exec_mismatch or output_mismatch')
inconsistent.to_csv("/users/user42/difftest/inconsistents.csv", index=True)

if 'exec_mismatch' in df.columns:
    df_exec_mismatch = df[df['exec_mismatch'] == True].copy()
else:
    # If exec_mismatch not present, assume all rows are exec mismatches
    df_exec_mismatch = df.copy()

# Identify execution return code columns
exec_cols = [col for col in df_exec_mismatch.columns if col.startswith('exec_rc_')]

# Compute unique exec return codes and their counts per (program, flags)
summary = (
    df_exec_mismatch
    .groupby(['program', 'flags'])[exec_cols]
    .agg(lambda s: sorted(set(s.dropna())))
    .rename(columns={col: f"{col}" for col in exec_cols})
    .reset_index()
)

# Also compute number of distinct exec rc values
summary['distinct_exec_rc_count'] = summary[[f"{col}_uniq" for col in exec_cols]].apply(lambda row: len(set().union(*row)), axis=1)



output_file_path_rc = '/users/user42/difftest/hash1-mismatches_return‑code_analysis.csv'

try:
    summary.to_csv(output_file_path_rc, index=False)
    print(f"DataFrame successfully saved to '{output_file_path_rc}'")
except Exception as e:
    print(f"An error occurred while saving the file: {e}")

if 'output_mismatch' in df.columns:
    df_output_mismatch = df[df['output_mismatch'] == True].copy()
    print("DataFrame filtered for output mismatches:")
    display(df_output_mismatch.head())
else:
    print("The 'output_mismatch' column does not exist in the DataFrame.")
    df_output_mismatch = pd.DataFrame() # Create an empty DataFrame if the column is missing

output_cols = [col for col in df_output_mismatch.columns if col.startswith('exec_stdout_hash_clang-')]

def analyze_outputs(row):
    outputs = [row[col] for col in output_cols]
    distinct_outputs = set(outputs)
    count = len(distinct_outputs)

    versions_info = {}
    if count > 1:
        if count == 2:
            # Find the two distinct outputs
            output1, output2 = list(distinct_outputs)
            versions_with_output1 = [output_cols[i] for i, output in enumerate(outputs) if output == output1]
            versions_with_output2 = [output_cols[i] for i, output in enumerate(outputs) if output == output2]

            # Determine which group has two versions and which has one
            if len(versions_with_output1) == 2:
                versions_info['same'] = versions_with_output1
                versions_info['different'] = versions_with_output2
            else:
                versions_info['same'] = versions_with_output2
                versions_info['different'] = versions_with_output1
        else:
             # For more than 2 distinct outputs, list all versions that are different from the first
            baseline_output = outputs[0]
            versions_info['different'] = [output_cols[i] for i, output in enumerate(outputs) if output != baseline_output]


    return count, versions_info

# Apply the function to create the new columns
df_output_mismatch[['distinct_output_count', 'versions_with_different_output']] = df_output_mismatch.apply(analyze_outputs, axis=1, result_type='expand')

output_file_path_stdout = '/users/user42/difftest/hash1_mismatch_stdout_analysis.csv'

try:
    df_output_mismatch.to_csv(output_file_path_stdout, index=False)
    print(f"DataFrame successfully saved to '{output_file_path_stdout}'")
except Exception as e:
    print(f"An error occurred while saving the file: {e}")
