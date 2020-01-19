//
// Created by 刘丰恺 on 17/1/2020.
//

#ifndef LLVM_RUNNER_CODE_GEN_H
#define LLVM_RUNNER_CODE_GEN_H

#include "utils/common.h"

struct Generator {

};

class CodeGen {
public:
    CodeGen(llvm::Type *t = nullptr);

    virtual ~ CodeGen() {}

public:
    llvm::Type *type = nullptr;
    llvm::Value *value = nullptr;

    bool isParams = false;
    bool isEscape = false;
public:
    virtual llvm::Value *generate(const Generator &generator);

    llvm::Value *load(llvm::IRBuilder<> &builder, llvm::Value *v);

protected:
    virtual llvm::Value *gen(const Generator &generator) = 0;
};


#endif //LLVM_RUNNER_CODE_GEN_H
