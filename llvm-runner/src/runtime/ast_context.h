//
// Created by 刘丰恺 on 17/1/2020.
//

#ifndef LLVM_RUNNER_AST_CONTEXT_H
#define LLVM_RUNNER_AST_CONTEXT_H

#include "utils/common.h"

class AstContext {
public:
    explicit AstContext(AstContext *p);

    explicit AstContext(llvm::Module *m);

public:
    AstContext *parent = nullptr;
    llvm::Module *module = nullptr;
    QString path_name;

public:
    llvm::LLVMContext &context();
};


#endif //LLVM_RUNNER_AST_CONTEXT_H
