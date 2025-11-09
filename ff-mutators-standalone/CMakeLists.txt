cmake_minimum_required(VERSION 3.16)
project(grayc_mutators LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

# Enable the CLI 'main()' inside each mutator (writes <file>.mutated.c).
add_compile_definitions(GRAYC_BUILD_TOOL=1)

find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

message(STATUS "Found LLVM: ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Using ClangConfig.cmake in: ${Clang_DIR}")

include_directories(${LLVM_INCLUDE_DIRS} ${CLANG_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

find_library(CLANG_CPP_LIB clang-cpp HINTS ${LLVM_LIBRARY_DIRS})
set(CLANG_LIB
  clangTooling clangFrontend clangSerialization clangParse clangSema
  clangAnalysis clangAST clangBasic clangEdit clangLex clangDriver
  clangRewrite
  LLVMCore LLVMSupport LLVMOption
)

add_library(grayc_utils STATIC
  utils-fuzzer/GrayCCustomRandom.cpp
  utils-fuzzer/GrayCCustomRandom.h
  utils-fuzzer/GrayCUtils.cpp
  utils-fuzzer/GrayCUtils.h
  utils-fuzzer/GrayCAggressivenessConsts.h
)
target_include_directories(grayc_utils PUBLIC utils-fuzzer)

# --- Helper to produce one binary per mutator (flat layout as in your screenshot)
function(make_mutator name)
  add_executable(${name}
    grayc/${name}.cpp
    grayc/${name}.h
  )
  target_include_directories(${name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/grayc)
  target_link_libraries(${name} PRIVATE grayc_utils ${CLANG_LIB})
endfunction()

make_mutator(JumpMutator)
make_mutator(ExpressionMutator)
make_mutator(DuplicateMutator)
make_mutator(ConstantMutator)
make_mutator(DeleteMutator)
