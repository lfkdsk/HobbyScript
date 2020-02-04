//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_RUNTIME_H
#define LLVM_RUNNER_RUNTIME_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include "common/common.h"
#include "ast_context.h"
#include "ast/ast_nodes.hpp"

/* LLVM Runtime */
extern llvm::LLVMContext llvm_global_context;
extern std::unique_ptr<llvm::Module> llvm_module;
extern QMap<QString, AstContext *> global_packages_contexts;
extern QMap<QString, AstPackage *> global_packages;

/* C Plugin Runtime */
extern QMap<QString, llvm::Module *> loaded_modules;
extern QMap<QString, llvm::StructType *> loaded_structs;

/* Ast Runtime */
extern AstPackage *ast_current_package;

/* Lex & Yacc RunTime */
extern int yydebug, yylineno;

/* logger console */
extern std::shared_ptr<spdlog::logger> console;

extern llvm::ExecutionEngine *build_llvm_engine(std::unique_ptr<llvm::Module> module);

#endif //LLVM_RUNNER_RUNTIME_H
