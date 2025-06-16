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
        cp "$file" llvmSS-include/
        ((c_count++))
    elif [[ "$file" == *.h ]]; then
        cp "$file" llvmSS-include/
    fi
  done
  
cd ~
git clone https://github.com/llvm/llvm-project.git
cd llvm-project
git checkout release/17.x
mkdir ~/build-clang17
cd ~/build-clang17

# Configure LLVM build to use AFL's clang-fast
LD=/usr/local/bin/afl-clang-fast++ cmake -G Ninja -Wall ../llvm-project/llvm/ \
  -DLLVM_ENABLE_PROJECTS="clang" \
  -DLLVM_USE_SANITIZER=OFF \
  -DCMAKE_BUILD_TYPE="Release" \
  -DCMAKE_C_COMPILER=/usr/local/bin/afl-clang-fast \
  -DCMAKE_CXX_COMPILER=/usr/local/bin/afl-clang-fast++ \
  -DBUILD_SHARED_LIBS=OFF \
  -DLLVM_TARGETS_TO_BUILD="X86" \
  -DCMAKE_C_FLAGS="-pthread -L/usr/lib/x86_64-linux-gnu" \
  -DCMAKE_CXX_FLAGS="-pthread -L/usr/lib/x86_64-linux-gnu" \
  -DCMAKE_EXE_LINKER_FLAGS="-L/usr/lib/x86_64-linux-gnu" \
  -DLLVM_BUILD_DOCS="OFF"
  
# Build only clang 
ninja clang  

AFL_DEBUG=1 AFL_USE_ASAN=0 AFL_PRINT_FILENAMES=1 AFL_DEBUG_CHILD_OUTPUT=1 \ 
afl-cmin -i /users/user42/llvmSS-c-corpus -o /users/user42/llvmSS-c-corpus-after-Cmin \
-m none -t 500 -T 12 -- /users/user42/build-clang17/bin/clang -x c -c -O3 -fpermissive \
-w -Wno-implicit-function-declaration -Wno-implicit-int -Wno-return-type -Wno-builtin-redeclared -Wno-int-conversion  \
-march=native -I/usr/include -I/users/user42/llvmSS-include @@  -o /dev/null > /users/user42/afl-cmin-errors.log 2>&1

mkdir -p llvmSS-minimised-corpus && cd llvmSS-minimised-corpus
i=0
for file in /users/user42/llvmSS-c-corpus-after-Cmin/*; do
    cp "$file" "test_$i.c"
    ((i++))
done
cd ~
tar -czvf llvmSS-minimised-corpus.tar.gz -C /users/user42/ llvmSS-minimised-corpus llvmSS-include
tar -czvf llvmSS-corpus.tar.gz -C /users/user42/ llvmSS-c-corpus llvmSS-include
