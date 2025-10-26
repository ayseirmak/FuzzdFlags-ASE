add_clang_tool(clang-options
  clang-options.cpp
)

# Map LLVM components to actual libs. No X86AsmPrinter!
llvm_map_components_to_libnames(LLVM_X86_LIBS
  Core Support Option Target
  MC MCParser
  AsmParser AsmPrinter      # generic, not per-target
  X86Info X86Desc X86AsmParser X86CodeGen
  BitWriter
)

target_link_libraries(clang-options
  PRIVATE
    clangDriver
    clangFrontend
    clangFrontendTool
    clangCodeGen
    clangSerialization
    clangAST
    clangLex
    clangBasic
    ${LLVM_X86_LIBS}
)
