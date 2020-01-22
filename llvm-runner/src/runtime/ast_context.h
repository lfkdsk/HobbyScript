//
// Created by 刘丰恺 on 17/1/2020.
//

#ifndef LLVM_RUNNER_AST_CONTEXT_H
#define LLVM_RUNNER_AST_CONTEXT_H

#include "common/common.h"
#include "gen/code_gens.hpp"
#include "common/utility.h"

class AstContext {
public:
    explicit AstContext(AstContext *p);

    explicit AstContext(llvm::Module *m);

public:
    AstContext *parent = nullptr;
    llvm::Module *module = nullptr;
    QString path_name;
    QHash<QString, CodeGen *> symbols;

public:
    llvm::LLVMContext &context();

    // symbols
    CodeGen *find_symbol_value(const QString &var_name, bool recursive = true);

    void set_symbol_value(const QString &var_name, CodeGen *value);

    // classes
    AstDefClass *find_class(const QString &name);
};


#endif //LLVM_RUNNER_AST_CONTEXT_H
