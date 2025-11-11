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

# --- delete-mutator tool ---
add_executable(delete-mutator
  delete-mutator/DeleteMutator.cpp
)
target_include_directories(delete-mutator PRIVATE
  delete-mutator
  utils-fuzzer
)

target_link_libraries(delete-mutator
  PRIVATE
    utils-fuzzer
    clangTooling
    clangBasic
    clangASTMatchers
)

# --- duplicate-mutator tool ---
add_executable(duplicate-mutator
  duplicate-mutator/DuplicateMutator.cpp
)
target_include_directories(duplicate-mutator PRIVATE
  duplicate-mutator
  utils-fuzzer
)

target_link_libraries(duplicate-mutator
  PRIVATE
    utils-fuzzer
    clangTooling
    clangBasic
    clangASTMatchers
)

# --- jump-mutator tool ---
add_executable(jump-mutator
  jump-mutator/JumpMutator.cpp
)
target_include_directories(jump-mutator PRIVATE
  jump-mutator
  utils-fuzzer
)

target_link_libraries(jump-mutator
  PRIVATE
    utils-fuzzer
    clangTooling
    clangBasic
    clangASTMatchers
)

# --- expression-mutator tool ---
add_executable(expression-mutator
  expression-mutator/ExpressionMutator.cpp
)
target_include_directories(expression-mutator PRIVATE
  expression-mutator
  utils-fuzzer
)

target_link_libraries(expression-mutator
  PRIVATE
    utils-fuzzer
    clangTooling
    clangBasic
    clangASTMatchers
)