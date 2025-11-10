cmake_minimum_required(VERSION 3.16)
project(grayc_constant_mutator LANGUAGES C CXX)   # <-- add C

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "LLVM DIR:  ${LLVM_DIR}")
message(STATUS "Clang DIR: ${Clang_DIR}")

add_definitions(${LLVM_DEFINITIONS})
include_directories(SYSTEM ${LLVM_INCLUDE_DIRS} ${CLANG_INCLUDE_DIRS})

# --- utils-fuzzer (random + helpers) ---
add_library(utils-fuzzer STATIC
  utils-fuzzer/GrayCCustomRandom.cpp
  utils-fuzzer/GrayCUtils.cpp
)
target_include_directories(utils-fuzzer PUBLIC mutators/utils-fuzzer)

# --- constant-mutator tool ---
add_executable(constant-mutator
  constant-mutator/ConstantMutator.cpp
)
target_include_directories(constant-mutator PRIVATE
  constant-mutator
  utils-fuzzer
)

target_link_libraries(constant-mutator
  PRIVATE
    utils-fuzzer
    clangTooling
    clangBasic
    clangASTMatchers
)
