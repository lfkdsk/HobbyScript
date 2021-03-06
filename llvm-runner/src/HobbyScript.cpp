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
#include "runtime/runtime.h"
#include "plugins/string.h"

int main(int argc, char **argv, char *const *envp) {
    atexit(llvm::llvm_shutdown);
//    ::testing::InitGoogleTest(&argc, argv);
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    auto *m = new llvm::Module("TOP", llvm_global_context);
    llvm_module.reset(m);

    start_gc(argc);
    auto *var = HNI_StringObject_FromString("lfkdsk", 6);
    HNI_StringObject_Finalize(var);
    stop_gc();
    return 0;
}
