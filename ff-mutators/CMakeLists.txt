cmake_minimum_required(VERSION 3.16)
project(ff_mutators LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(LLVM  REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

message(STATUS "Using LLVM at: ${LLVM_DIR}")
message(STATUS "Using Clang at: ${Clang_DIR}")
include_directories(${LLVM_INCLUDE_DIRS} ${CLANG_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

file(GLOB UTIL_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/utils-fuzzer/*.cpp")

add_library(grayc_core STATIC
  grayc/ConstantMutator.cpp
  grayc/DeleteMutator.cpp
  grayc/DuplicateMutator.cpp
  grayc/ExpressionMutator.cpp
  grayc/JumpMutator.cpp
  ${UTIL_SOURCES}
)

target_compile_definitions(grayc_core PRIVATE GRAYC_BUILD_TOOL=0)
target_include_directories(grayc_core PRIVATE
  ${CMAKE_SOURCE_DIR}/grayc
  ${CMAKE_SOURCE_DIR}/utils-fuzzer
)
target_link_libraries(grayc_core PRIVATE
  clangTooling clangASTMatchers clangBasic clangFrontend
)

# -------- AFL++ custom mutator: libgrayc_const.so ----------
add_library(grayc_const SHARED
  mutators/grayc_const_custom_mutator.cpp
)
target_include_directories(grayc_const PRIVATE
  ${CMAKE_SOURCE_DIR}/mutators
  ${CMAKE_SOURCE_DIR}/grayc
  ${CMAKE_SOURCE_DIR}/utils-fuzzer
)
target_link_libraries(grayc_const PRIVATE
  grayc_core
  clangTooling clangASTMatchers clangBasic clangFrontend
)

# -------- AFL++ custom mutator: libgrayc_delete.so ----------
add_library(grayc_delete SHARED
  mutators/grayc_delete_custom_mutator.cpp
)
target_include_directories(grayc_delete PRIVATE
  ${CMAKE_SOURCE_DIR}/mutators
  ${CMAKE_SOURCE_DIR}/grayc
  ${CMAKE_SOURCE_DIR}/utils-fuzzer
)
target_link_libraries(grayc_delete PRIVATE
  grayc_core
  clangTooling clangASTMatchers clangBasic clangFrontend
)

# -------- AFL++ custom mutator: libgrayc_duplicate.so ----------
add_library(grayc_duplicate SHARED
  mutators/grayc_duplicate_custom_mutator.cpp
)
target_include_directories(grayc_duplicate PRIVATE
  ${CMAKE_SOURCE_DIR}/mutators
  ${CMAKE_SOURCE_DIR}/grayc
  ${CMAKE_SOURCE_DIR}/utils-fuzzer
)
target_link_libraries(grayc_duplicate PRIVATE
  grayc_core
  clangTooling clangASTMatchers clangBasic clangFrontend
)

# -------- AFL++ custom mutator: libgrayc_expression.so ----------
add_library(grayc_expression SHARED
  mutators/grayc_expression_custom_mutator.cpp
)
target_include_directories(grayc_expression PRIVATE
  ${CMAKE_SOURCE_DIR}/mutators
  ${CMAKE_SOURCE_DIR}/grayc
  ${CMAKE_SOURCE_DIR}/utils-fuzzer
)
target_link_libraries(grayc_expression PRIVATE
  grayc_core
  clangTooling clangASTMatchers clangBasic clangFrontend
)

# -------- AFL++ custom mutator: libgrayc_jump.so ----------
add_library(grayc_jump SHARED
  mutators/grayc_jump_custom_mutator.cpp
)
target_include_directories(grayc_jump PRIVATE
  ${CMAKE_SOURCE_DIR}/mutators
  ${CMAKE_SOURCE_DIR}/grayc
  ${CMAKE_SOURCE_DIR}/utils-fuzzer
)
target_link_libraries(grayc_jump PRIVATE
  grayc_core
  clangTooling clangASTMatchers clangBasic clangFrontend
)