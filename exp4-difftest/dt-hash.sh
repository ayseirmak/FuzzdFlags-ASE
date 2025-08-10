#!/usr/bin/env bash
# Base path for sources and includes
BASE_DIR="$HOME"
CORPUS_DIR="$BASE_DIR/llvmSS-minimised-corpus"
INCLUDE_DIR="$BASE_DIR/llvmSS-include"

# Compilers to test
declare -A COMPILERS=(
  [clang-17]="$BASE_DIR/build/bin/clang-17"
  [clang-19]="$BASE_DIR/llvm-19-build/bin/clang-19"
  [clang-22]="$BASE_DIR/llvm-latest-build/bin/clang-22"
)

# Common Clang flags
COMMON_FLAGS=(
  -std=gnu89
  -fpermissive -w
  -Wno-implicit-function-declaration
  -Wno-implicit-int
  -Wno-return-type
  -Wno-builtin-declaration-mismatch
  -Wno-int-conversion
  -march=native
  -lm
  -I/usr/include
  -I"$INCLUDE_DIR"
)

# Timeouts (in seconds)
COMPILE_TIMEOUT=60
EXEC_TIMEOUT=30

# Input/Output files
SEEDS_FILE="/users/user42/unique_pairs.csv"
OUTPUT_CSV="seed_results_1000000_hash.csv"
LOG_ROOT="runs_hash"

# Clean old output
rm -f "$OUTPUT_CSV"
mkdir -p "$LOG_ROOT"

echo 'program,flags,compiler,compile_rc,compile_stdout_hash,compile_stderr_hash,exec_rc,exec_stdout_hash,exec_stderr_hash' > "$OUTPUT_CSV"

# Read and skip header
count=0
tail -n +2 "$SEEDS_FILE" | while IFS=, read -r source_file flags_field; do
  # Strip surrounding quotes (if any)
  source_file="${source_file%\"}"
  source_file="${source_file#\"}"
  flags_field="${flags_field%\"}"
  flags_field="${flags_field#\"}"

  # Extract program basename (without .c)
  prog=$(basename "$source_file" .c)
  src_path="$CORPUS_DIR/$prog.c"

  # Skip if source missing
  if [[ ! -f "$src_path" ]]; then
    echo "⚠️  Missing source $src_path, skipping."
    continue
  fi

  # Determine if we need an argv[1] argument
  if grep -qE '\bargv[[:space:]]*\[\s*1\s*\]' "$src_path"; then
    USE_ARG=1
  else
    USE_ARG=0
  fi

  # Prepare flags array
  if [[ -z "$flags_field" ]]; then
    flags_array=()
  else
    read -r -a flags_array <<< "$flags_field"
  fi

  # Iterate compilers
  for label in "${!COMPILERS[@]}"; do
    clang_bin=${COMPILERS[$label]}
    ((count++))
    echo "[$count] $prog @ $label"

    # Create log directory
    run_id=$(printf '%s' "$flags_field" | sha256sum | cut -c1-12)
    run_dir="$LOG_ROOT/$prog/$label/$run_id"
    mkdir -p "$run_dir"
    # Compile: separate stdout/stderr
    compile_stdout="$run_dir/compile.stdout"
    compile_stderr="$run_dir/compile.stderr"

    timeout $COMPILE_TIMEOUT "$clang_bin" "${COMMON_FLAGS[@]}" "${flags_array[@]}" \
      -o "$run_dir/$prog" "$src_path" \
      >"$compile_stdout" 2>"$compile_stderr"
    c_rc=$?

    #  Compute hashes of compile outputs
    csout=$(sha256sum "$compile_stdout" | cut -d' ' -f1)
    cserr=$(sha256sum "$compile_stderr" | cut -d' ' -f1)

    # csout=$(sed ':a;N;s/"/""/g;s/\n/\\n/g;ta' "$compile_stdout")
    # cserr=$(sed ':a;N;s/"/""/g;s/\n/\\n/g;ta' "$compile_stderr")

    # Execute if compiled
    exec_stdout="$run_dir/exec.stdout"
    exec_stderr="$run_dir/exec.stderr"
    if [[ $c_rc -eq 0 ]]; then
      if [[ $USE_ARG -eq 1 ]]; then
        timeout $EXEC_TIMEOUT "$run_dir/$prog" 1000000 >"$exec_stdout" 2>"$exec_stderr"
      else
        timeout $EXEC_TIMEOUT "$run_dir/$prog" >"$exec_stdout" 2>"$exec_stderr"
      fi
      e_rc=$?
    else
      e_rc=124
      echo "" >"$exec_stdout"  # empty
      echo "<skipped>" >"$exec_stderr"
    fi

    #  Compute hashes of exec outputs
    esout=$(sha256sum "$exec_stdout" | cut -d' ' -f1)
    eserr=$(sha256sum "$exec_stderr" | cut -d' ' -f1)

    # Append to CSV using printf for robust quoting
    printf '"%s","%s","%s",%d,"%s","%s",%d,"%s","%s"\n' \
      "$prog" "$flags_field" "$label" $c_rc "$csout" "$cserr" $e_rc "$esout" "$eserr" \
      >> "$OUTPUT_CSV"
  done

done

echo "✅ All runs complete; summary in $OUTPUT_CSV"
