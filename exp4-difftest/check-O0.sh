#!/usr/bin/env bash
set -euo pipefail

# ─── 1) Define your three compiler versions ────────────────────────────
COMPILERS=(clang-17 clang-19 clang-22)

# ─── 2) C standard and flags ──────────────────────────────────────────
STD="-std=gnu89"   # maximum backward compatibility (old K&R code + GNU extensions)
COMMON_FLAGS=(
  -O0
  $STD
  -fpermissive
  -w
  -Wno-implicit-function-declaration
  -Wno-implicit-int
  -Wno-return-type
  -Wno-builtin-declaration-mismatch
  -Wno-int-conversion
  -march=native
  -lm
  -I/usr/include
  -I"${INCLUDES_DIR:-.}"
)

# ─── 3) Collect all .c files ───────────────────────────────────────────
PROGRAMS=( *.c )
TOTAL=${#PROGRAMS[@]}
echo "Found $TOTAL programs to test."

# ─── 4) Prepare output directories ────────────────────────────────────
BASELOG="golden_reference"
rm -rf "$BASELOG"
mkdir -p "$BASELOG"/{logs,summary}

# Summary CSV header
echo "program,compiler,comp_rc,exec_rc,compile_stdout,compile_stderr,exec_stdout,exec_stderr" \
  > "$BASELOG/summary/results.csv"

# ─── 5) Loop over each program and compiler ────────────────────────────
for SRC in "${PROGRAMS[@]}"; do
  NAME="${SRC%.c}"
  echo "=== Testing $SRC ==="
  
  # Track if outputs are consistent across compilers
  declare -A comp_rc exec_rc

  for COMP in "${COMPILERS[@]}"; do
    OUTDIR="$BASELOG/logs/$NAME/$COMP"
    mkdir -p "$OUTDIR"
    
    BIN="$OUTDIR/$NAME"
    
    # 5a) Compile, capture stdout/stderr
    echo "[ $COMP ] Compiling..."
    "${COMP}" "${COMMON_FLAGS[@]}" -o "$BIN" "$SRC" \
      >"$OUTDIR/compile.stdout" \
      2>"$OUTDIR/compile.stderr"
    comp_rc[$COMP]=$?
    
    # 5b) Run only if compile succeeded
    if [ "${comp_rc[$COMP]}" -eq 0 ]; then
      echo "[ $COMP ] Executing..."
      "$BIN" \
        >"$OUTDIR/exec.stdout" \
        2>"$OUTDIR/exec.stderr"
      exec_rc[$COMP]=$?
    else
      exec_rc[$COMP]="<no-run>"
      touch "$OUTDIR/exec.stdout" "$OUTDIR/exec.stderr"
    fi

    # 5c) Append to summary CSV (escape quotes)
    csout=$(sed 's/"/""/g' "$OUTDIR/compile.stdout")
    cserr=$(sed 's/"/""/g' "$OUTDIR/compile.stderr")
    esout=$(sed 's/"/""/g' "$OUTDIR/exec.stdout")
    eserr=$(sed 's/"/""/g' "$OUTDIR/exec.stderr")
    echo "\"$NAME\",\"$COMP\",${comp_rc[$COMP]},${exec_rc[$COMP]},\"$csout\",\"$cserr\",\"$esout\",\"$eserr\"" \
      >> "$BASELOG/summary/results.csv"
  done

  # 5d) Check for consistency of return codes
  unique_comp_rc=$(printf "%s\n" "${comp_rc[@]}" | sort -u | wc -l)
  unique_exec_rc=$(printf "%s\n" "${exec_rc[@]}" | sort -u | wc -l)

  if [ "$unique_comp_rc" -ne 1 ] || [ "$unique_exec_rc" -ne 1 ]; then
    echo ">>> Inconsistent behavior detected; marking $SRC for removal."
    echo "$SRC" >> "$BASELOG/summary/bad_tests.lst"
  fi

  echo
done

echo "Step 1 complete. Logs and summary in '$BASELOG/'."
echo "- 'logs/<program>/<compiler>/' holds separate stdout/stderr files."
echo "- 'summary/results.csv' aggregates all return codes and outputs."
echo "- 'summary/bad_tests.lst' lists programs with inconsistent -O0 behavior."
