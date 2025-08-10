#!/usr/bin/env bash

if [ "$#" -lt 2 ]; then
  echo "Usage: $0 <test-number> \"<flags>\""
  exit 1
fi

# ─── parameters ────────────────────────────────────────────────────────────────
no="$1"      
shift        
flags=("$@") 

COMPILE_TIMEOUT=60          # seconds
EXEC_TIMEOUT=60

COMP17="/users/user42/build/bin/clang-17"
COMP19="/users/user42/llvm-19-build/bin/clang-19"
COMP22="/users/user42/llvm-latest-build/bin/clang-22"

SRC="/users/user42/llvmSS-minimised-corpus/test_${no}.c"
rm -f /tmp/test_*
BIN17="/tmp/test_${no}_17.out"
BIN19="/tmp/test_${no}_19.out"
BIN22="/tmp/test_${no}_22.out"

OUT17="/tmp/test_${no}_17.stdout"
OUT19="/tmp/test_${no}_19.stdout"
OUT22="/tmp/test_${no}_22.stdout"

STD="-std=gnu89"            # maximum backward compatibility
COMMON_FLAGS=(
  "$STD"
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

# ─── compile each version ──────────────────────────────────────────────────────
echo "=== Compiling test_${no}.c with Clang-17,19,22 ==="
timeout "$COMPILE_TIMEOUT" "$COMP17" "${COMMON_FLAGS[@]}" "${flags[@]}" -o "$BIN17" "$SRC" 
rc17=$?
timeout "$COMPILE_TIMEOUT" "$COMP19" "${COMMON_FLAGS[@]}" "${flags[@]}" -o "$BIN19" "$SRC"
rc19=$?
timeout "$COMPILE_TIMEOUT" "$COMP22" "${COMMON_FLAGS[@]}" "${flags[@]}" -o "$BIN22" "$SRC"
rc22=$?

# ─── execute each version, capturing stdout ────────────────────────────────────
echo "=== Running binaries and capturing stdout (arg 1000000) ==="
timeout $EXEC_TIMEOUT "$BIN17" 1000000 > "$OUT17"
ex_rc17=$?
echo $ex_rc17
timeout $EXEC_TIMEOUT "$BIN19" 1000000 > "$OUT19"
ex_rc19=$?
timeout $EXEC_TIMEOUT "$BIN22" 1000000 > "$OUT22"
ex_rc22=$?

# ─── report return codes ───────────────────────────────────────────────────────
printf "\nCompile return codes:\n"
printf "  Clang-17: %3d   Clang-19: %3d   Clang-22: %3d\n" "$rc17" "$rc19" "$rc22"

printf "\nExecution return codes:\n"
printf "  Clang-17: %3d   Clang-19: %3d   Clang-22: %3d\n" "$ex_rc17" "$ex_rc19" "$ex_rc22"

# ─── compare stdout ────────────────────────────────────────────────────────────
echo
echo "=== Stdout comparison ==="
if diff -q "$OUT17" "$OUT19" >/dev/null && diff -q "$OUT17" "$OUT22" >/dev/null; then
  echo OUT17 "$OUT17"
  echo OUT19 "$OUT19"
  echo OUT22 "$OUT22"
  echo "All three compilers produced identical stdout."
else
  echo "Differences detected!"
  echo
  echo "--- Clang-17 vs Clang-19 ---"
  diff -u "$OUT17" "$OUT19" || true
  echo
  echo "--- Clang-17 vs Clang-22 ---"
  diff -u "$OUT17" "$OUT22" || true
  echo
  echo "--- Clang-19 vs Clang-22 ---"
  diff -u "$OUT19" "$OUT22" || true
fi
