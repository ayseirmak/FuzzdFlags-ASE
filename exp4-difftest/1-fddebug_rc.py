#!/usr/bin/env python3
import pandas as pd
import subprocess
import json
import re

# Paths and parameters
CSV_IN = '/users/user42/difftest/hash1-mismatches_return‑code_analysis.csv'
CSV_OUT = '/users/user42/difftest/hash1-mismatches_return‑code_analysis_min_combs.csv'
SCRIPT = './fddebug_min.py'
COMBO_SIZES = '1,2,3'

# Load DataFrame
df = pd.read_excel(EXCEL_IN)
print(f'Loaded {len(df)} rows from {EXCEL_IN}')
# Function to extract program number
prog_no_pattern = re.compile(r'(\d+)')

def get_prog_no(name):
    m = prog_no_pattern.search(name)
    return m.group(1) if m else name

# Columns to process
clang_versions = [17, 19, 22]

# Initialize columns
dtype_obj = pd.Series(dtype='object')
for ver in clang_versions:
    df[f'Min_Flag_comb_clang{ver}'] = dtype_obj.copy()

# Iterate rows
for idx, row in df.iterrows():
    prog = row['program']
    prog_no = get_prog_no(prog)
    print(f'Processing {prog} (No: {prog_no})')
    for ver in clang_versions:
        rc = row.get(f'exec_rc_clang-{ver}', 0)
        print(f'  Clang-{ver} return code: {rc}')
        if rc=="[134]" or rc=="[139]":
            # Build command
            cmd = [
                SCRIPT,
                str(ver),
                prog_no,
                COMBO_SIZES,
            ] + row['flags'].split()
            try:
                out = subprocess.check_output(cmd, universal_newlines=True, stderr=subprocess.DEVNULL)
                data = json.loads(out)
                print(f'Processed {prog} with clang-{ver}: {data}')
                df.at[idx, f'Min_Flag_comb_clang{ver}'] = json.dumps(data['min_flags'])
            except subprocess.CalledProcessError:
                df.at[idx, f'Min_Flag_comb_clang{ver}'] = ''

# Save to new CSV
df.to_csv(CSV_OUT, index=False)
print(f'Updated CSV saved to {CSV_OUT}')
