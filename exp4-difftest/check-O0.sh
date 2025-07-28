#!/usr/bin/env bash
# ─── 1) Define your three compiler versions by full build path ─────────
COMPILERS=(
  "$HOME/build/bin/clang-17"
  "$HOME/llvm-19-build/bin/clang-19"
  "$HOME/llvm-latest-build/bin/clang-22"
)


# ─── 2a) Timeout settings ─────────────────────────────────────────────
  # compile must finish within 60 seconds; adjust as needed
COMPILE_TIMEOUT="30s"
  # execution must finish within 10 seconds; adjust as needed
EXEC_TIMEOUT="5s"

# Optionally verify we’re pointing at the right binaries:
for C in "${COMPILERS[@]}"; do
  echo "Using compiler: $("$C" --version | head -n1)"
done

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
  -I"$HOME/llvmSS-include"
)

# ─── 3) Collect all .c files from your corpus ─────────────────────────
PROGRAMS=( "$HOME"/llvmSS-minimised-corpus/*.c )
TOTAL=${#PROGRAMS[@]}
echo "Found $TOTAL programs to test in ~/llvmSS-minimised-corpus."

# ─── 4) Prepare output directories ────────────────────────────────────
BASELOG="golden_reference"
rm -rf "$BASELOG"
mkdir -p "$BASELOG"/{logs,summary}

# Summary CSV header
echo "program,compiler,comp_rc,exec_rc,compile_stdout,compile_stderr,exec_stdout,exec_stderr" \
  > "$BASELOG/summary/results.csv"

# ─── 5) Loop over each program and compiler ────────────────────────────
for SRC in "${PROGRAMS[@]}"; do
  NAME="$(basename "$SRC" .c)"
  echo "=== Testing $NAME ==="
  
  declare -A comp_rc exec_rc

  for COMP in "${COMPILERS[@]}"; do
    LABEL="$(basename "$COMP")"
    OUTDIR="$BASELOG/logs/$NAME/$LABEL"
    mkdir -p "$OUTDIR"
    
    BIN="$OUTDIR/$NAME"
    
    # 5a) Compile, capture stdout/stderr
    echo "[ $LABEL ] Compiling..."
    timeout $COMPILE_TIMEOUT "$COMP" "${COMMON_FLAGS[@]}" -o "$BIN" "$SRC" \
      >"$OUTDIR/compile.stdout" \
      2>"$OUTDIR/compile.stderr"
    comp_rc[$LABEL]=$?
    
    # 5b) Run only if compile succeeded
    if [ "${comp_rc[$LABEL]}" -eq 0 ]; then
        if grep -q "argv\\[1\\]" "$SRC"; then
            ARGS="1000000"
        else
            ARGS=""
        fi
      echo "[ $LABEL ] Executing..."
      timeout $EXEC_TIMEOUT "$BIN" $ARGS \
        >"$OUTDIR/exec.stdout" \
        2>"$OUTDIR/exec.stderr"
      exec_rc[$LABEL]=$?
    else
      exec_rc[$LABEL]="<no-run>"
      : >"$OUTDIR/exec.stdout"
      : >"$OUTDIR/exec.stderr"
    fi

    # 5c) Append to summary CSV (escape quotes in outputs)
    csout=$(sed 's/"/""/g' "$OUTDIR/compile.stdout")
    cserr=$(sed 's/"/""/g' "$OUTDIR/compile.stderr")
    esout=$(sed 's/"/""/g' "$OUTDIR/exec.stdout")
    eserr=$(sed 's/"/""/g' "$OUTDIR/exec.stderr")
    echo "\"$NAME\",\"$LABEL\",${comp_rc[$LABEL]},${exec_rc[$LABEL]},\"$csout\",\"$cserr\",\"$esout\",\"$eserr\"" \
      >> "$BASELOG/summary/results.csv"
  done

  # 5d) Check for consistency of return codes
  unique_comp_rc=$(printf "%s\n" "${comp_rc[@]}" | sort -u | wc -l)
  unique_exec_rc=$(printf "%s\n" "${exec_rc[@]}" | sort -u | wc -l)

  if [ "$unique_comp_rc" -ne 1 ] || [ "$unique_exec_rc" -ne 1 ]; then
    echo ">>> Inconsistent behavior detected; marking $NAME for removal."
    echo "$NAME.c" >> "$BASELOG/summary/bad_tests.lst"
  fi

  echo
done

echo "Step 1 complete. Logs and summary are in '$BASELOG/'."
echo "- 'logs/<program>/<compiler>/' holds separate stdout/stderr files."
echo "- 'summary/results.csv' aggregates all return codes and outputs."
echo "- 'summary/bad_tests.lst' lists programs with inconsistent -O0 behavior."
