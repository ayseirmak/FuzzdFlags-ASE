#!/usr/bin/env bash
set -euo pipefail

# 1) List your clang binaries here
COMPILERS=(clang-12 clang-13 clang-14)

# 2) Pick your C standard (must be supported by all versions)
STD="-std=c11"

# 3) Find all .c files in the current directory
PROGRAMS=( *.c )

# Temporary storage
TMPDIR="$(mktemp -d)"
trap 'rm -rf "$TMPDIR"' EXIT

echo
echo "Testing ${#PROGRAMS[@]} programs with ${#COMPILERS[@]} compilers at -O0"
echo

for SRC in "${PROGRAMS[@]}"; do
  NAME="${SRC%.c}"
  echo "--- $SRC ---"

  declare -A compile_code run_code output

  # Compile & run under each compiler
  for COMP in "${COMPILERS[@]}"; do
    BIN="$TMPDIR/${NAME}-$COMP"
    echo -n "[$COMP] Compiling... "
    $COMP -O0 $STD -o "$BIN" "$SRC"
    compile_code[$COMP]=$?
    echo "exit=${compile_code[$COMP]}"

    if [ "${compile_code[$COMP]}" -eq 0 ]; then
      echo -n "       Running… "
      # capture both exit code and stdout
      OUT="$TMPDIR/out-$COMP.txt"
      "$BIN" >"$OUT" 2>&1
      run_code[$COMP]=$?
      output[$COMP]="$(<"$OUT")"
      echo "exit=${run_code[$COMP]}"
    else
      echo "       (skipped run)"
      run_code[$COMP]="<no-binary>"
      output[$COMP]=""
    fi
  done

  # Compare results
  echo -n "  Compile codes equal? "
  if printf "%s\n" "${compile_code[@]}" | uniq | wc -l | grep -q '^1$'; then
    echo "✅"
  else
    echo "❌  ${compile_code[@]}"
  fi

  echo -n "  Run codes equal?     "
  if printf "%s\n" "${run_code[@]}" | uniq | wc -l | grep -q '^1$'; then
    echo "✅"
  else
    echo "❌  ${run_code[@]}"
  fi

  echo -n "  Stdout equal?        "
  # we diff all outputs pairwise
  FIRST="${output[${COMPILERS[0]}]}"
  SAME=true
  for COMP in "${COMPILERS[@]:1}"; do
    if [ "$FIRST" != "${output[$COMP]}" ]; then
      SAME=false
      break
    fi
  done
  if $SAME; then
    echo "✅"
  else
    echo "❌ (see \$TMPDIR/out-*.txt)"
  fi

  echo
done

