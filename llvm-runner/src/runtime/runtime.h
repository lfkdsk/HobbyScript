//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_RUNTIME_H
#define LLVM_RUNNER_RUNTIME_H

#include "utils/common.h"

/* LLVM Runtime */
llvm::LLVMContext llvm_global_context;
std::unique_ptr<llvm::Module> llvm_module;
std::map<QString, AstContext *> global_packages;

/* Ast Runtime */
AstPackage *ast_current_package = new AstPackage();

/* Lex & Yacc RunTime */
extern int yydebug, yylineno;


#endif //LLVM_RUNNER_RUNTIME_H
