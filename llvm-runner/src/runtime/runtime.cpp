//
// Created by 刘丰恺 on 20/1/2020.
//

#include "runtime.h"

llvm::LLVMContext llvm_global_context;
std::unique_ptr<llvm::Module> llvm_module;
QMap<QString, AstContext *> global_packages_contexts;
QMap<QString, AstPackage *> global_packages;

QMap<QString, llvm::Module *> loaded_modules;
QMap<QString, llvm::StructType *> loaded_structs;

/* Ast Runtime */
AstPackage *ast_current_package = new AstPackage();

std::shared_ptr<spdlog::logger> console = spdlog::stdout_color_mt("console");

llvm::ExecutionEngine *build_llvm_engine(std::unique_ptr<llvm::Module> module) {
    llvm::EngineBuilder builder(std::move(module));
    std::string err_msg;
    builder.setErrorStr(&err_msg);
//    builder.setEngineKind(llvm::EngineKind::Interpreter);

    llvm::StringRef MCPU = llvm::sys::getHostCPUName();
    console->debug(QString("MCPU: " + QString(MCPU.str().c_str())).toStdString());
    console->debug(QString("Triple: " + QString(llvm::sys::getDefaultTargetTriple().c_str())).toStdString());

    auto *engine = builder.create();
    if (!engine) {
        console->error(err_msg);
    }
    return engine;
}