cmake_minimum_required(VERSION 3.16)
project(ff_mutators_standalone LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build the CLI tools (enable main() via GRAYC_BUILD_TOOL)
option(GRAYC_BUILD_TOOLS "Build mutators as command-line tools" ON)

# --- Find LLVM & Clang (MUST be from the same install/prefix!)
# If CMake can't find these, pass:
#   -DLLVM_DIR=/path/to/llvm/lib/cmake/llvm
#   -DClang_DIR=/path/to/llvm/lib/cmake/clang
find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "LLVM_DIR  = ${LLVM_DIR}")
message(STATUS "Clang_DIR = ${Clang_DIR}")

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)
add_definitions(${LLVM_DEFINITIONS})

# Includes
include_directories(
  ${LLVM_INCLUDE_DIRS}
  ${CLANG_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/grayc
  ${CMAKE_CURRENT_SOURCE_DIR}/utils-fuzzer
)

# --- Prefer monolithic clang-cpp to avoid duplicate registrations
if (TARGET clang-cpp)
  set(CLANG_LIBS clang-cpp)
else()
  # Fallback to components (only if your install has no clang-cpp).
  # Keep this list minimal to reduce the chance of duplication.
  set(CLANG_LIBS
      clangTooling
      clangFrontend
      clangAST
      clangBasic
      clangLex
      clangRewrite
      clangSerialization
      clangDriver
      clangParse
      clangEdit
      clangSema
  )
endif()

# Common utility sources
set(GRAYC_COMMON_SOURCES
  utils-fuzzer/GrayCUtils.cpp
  utils-fuzzer/GrayCCustomRandom.cpp
)

# Helper: add one mutator (as a library and, optionally, an executable)
function(add_grayc_mutator NAME)
  set(SRC grayc/${NAME}.cpp)
  if (NOT EXISTS "${SRC}")
    message(WARNING "Skipping ${NAME}: ${SRC} not found")
    return()
  endif()

  # Library variant (no main())
  add_library(${NAME}_lib STATIC ${SRC} ${GRAYC_COMMON_SOURCES})
  target_link_libraries(${NAME}_lib PRIVATE ${CLANG_LIBS})
  target_compile_definitions(${NAME}_lib PRIVATE
    __STDC_CONSTANT_MACROS __STDC_LIMIT_MACROS)

  # Executable variant (standalone tool with main())
  if (GRAYC_BUILD_TOOLS)
    add_executable(${NAME} ${SRC} ${GRAYC_COMMON_SOURCES})
    target_link_libraries(${NAME} PRIVATE ${CLANG_LIBS})
    target_compile_definitions(${NAME} PRIVATE
      GRAYC_BUILD_TOOL=1
      __STDC_CONSTANT_MACROS __STDC_LIMIT_MACROS)
  endif()
endfunction()

# Add the mutators you have sources for:
add_grayc_mutator(ConstantMutator)
# add_grayc_mutator(DeleteMutator)
# add_grayc_mutator(DuplicateMutator)
# add_grayc_mutator(ExpressionMutator)
# add_grayc_mutator(JumpMutator)
