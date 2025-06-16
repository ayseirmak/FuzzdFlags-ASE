./AFLplusplus-latest-build.sh
git clone --depth 1 https://github.com/llvm/llvm-test-suite.git
cd llvm-test-suite
cp -r SingleSource ../
cd ..
rm -rf llvm-test-suite
mkdir -p llvmSS-c-corpus
mkdir -p llvmSS-include

c_count=0
find SingleSource -type f \( -name "*.c" -o -name "*.h" \) \
  ! -path "SingleSource/Regression/C/gcc-c-torture/execute/builtins" | while read -r file; do

    if [[ "$file" == *.c ]]; then
        cp "$file" "llvmSS-c-corpus/test_${c_count}.c"
        ((c_count++))
    elif [[ "$file" == *.h ]]; then
        cp "$file" llvmSS-include/
    fi
  done
tar -czvf llvmSS-corpus.tar.gz -C /users/user42/ llvmSS-c-corpus llvmSS-include
