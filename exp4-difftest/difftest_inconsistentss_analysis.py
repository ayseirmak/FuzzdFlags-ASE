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
