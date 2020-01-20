//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_RUNTIME_H
#define LLVM_RUNNER_RUNTIME_H

#include "utils/common.h"
#include "ast_context.h"
#include "ast/ast_nodes.hpp"

/* LLVM Runtime */
extern llvm::LLVMContext llvm_global_context;
extern std::unique_ptr<llvm::Module> llvm_module;
extern std::map<QString, AstContext *> global_packages;

/* Ast Runtime */
extern AstPackage *ast_current_package;

/* Lex & Yacc RunTime */
extern int yydebug, yylineno;


#endif //LLVM_RUNNER_RUNTIME_H
