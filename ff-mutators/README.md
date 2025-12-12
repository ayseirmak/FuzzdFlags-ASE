ff-mutators/
  CMakeLists.txt
  build/
  grayc/
    ConstantMutator.h
    ConstantMutator.cpp
    JumpMutator.h
    JumpMutator.cpp
    DeleteMutator.h
    DeleteMutator.cpp
    DuplicateMutator.h
    DuplicateMutator.cpp
    ExpressionMutator.h
    ExpressionMutator.cpp                
  mutators/
    mutator_common.h
    grayc_const_custom_mutator.cpp
    grayc_jump_custom_mutator.cpp
    grayc_expression_custom_mutator.cpp
    grayc_delete_custom_mutator.cpp
    grayc_duplicate_custom_mutator.cpp
  utils-fuzzers/

cd ff-mutators/
mkdir -p build && cd build
cmake -G Ninja \
  -DCMAKE_C_COMPILER=/usr/bin/clang-12 \
  -DCMAKE_CXX_COMPILER=/usr/bin/clang++-12 \
  -DLLVM_DIR=/usr/lib/llvm-12/lib/cmake/llvm \
  -DClang_DIR=/usr/lib/llvm-12/lib/cmake/clang \
  -DCMAKE_BUILD_TYPE=Release ..
ninja

cd ~
g++ -std=c++17 -O2 -Wall -Wextra -o mutator_probe mutator_probe.cpp -ldl
export LD_LIBRARY_PATH=/usr/lib/llvm-14/lib:$LD_LIBRARY_PATH
./mutator_probe ./ff-mutators/build/libgrayc_const.so ./seeds/seed0.c 1
