#include <iostream>
#include <fstream>
#include <llvm/Support/raw_ostream.h>
#include "spdlog/sinks/stdout_sinks.h"
#include "llvm/IR/LegacyPassManager.h"
#include "gtest/gtest.h"
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/Signals.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/ExecutionEngine/JITEventListener.h>
#include <llvm/IR/AssemblyAnnotationWriter.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/SourceMgr.h>
#include "ast/ast_nodes.hpp"

/* LLVM Runtime */
llvm::LLVMContext llvm_global_context;
std::unique_ptr<llvm::Module> llvm_module;

/* Ast Runtime */
AstPackage *ast_current_package = new AstPackage();

/* Lex & Yacc RunTime */
extern int yydebug, yylineno;

int main(int argc, char **argv) {
    atexit(llvm::llvm_shutdown);
//    ::testing::InitGoogleTest(&argc, argv);
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    auto *m = new llvm::Module("TOP", llvm_global_context);
    llvm_module.reset(m);

    return 0;
}
