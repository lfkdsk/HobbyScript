#include <iostream>
#include <fstream>
#include <rapidjson/document.h>
#include <gen/literals/generator_literals.h>
#include <llvm/Support/raw_ostream.h>
#include "visitor/AstVisitor.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "gen/generator_context.h"
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

llvm::LLVMContext llvmContext;
std::unique_ptr<llvm::Module> module;

int main(int argc, char **argv) {
//    atexit(llvm::llvm_shutdown);
//    ::testing::InitGoogleTest(&argc, argv);
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    auto *m = new llvm::Module("TOP", llvmContext);
    module.reset(m);

    return 0;
}
