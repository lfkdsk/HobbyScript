//
// Created by 刘丰恺 on 20/1/2020.
//

#include "runtime.h"

llvm::LLVMContext llvm_global_context;
std::unique_ptr<llvm::Module> llvm_module;
std::map<QString, AstContext *> global_packages;

/* Ast Runtime */
AstPackage *ast_current_package = new AstPackage();

std::shared_ptr<spdlog::logger> console = spdlog::stdout_color_mt("console");