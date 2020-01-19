//
// Created by 刘丰恺 on 19/1/2020.
//

#ifndef LLVM_RUNNER_TYPE_ONLY_GEN_H
#define LLVM_RUNNER_TYPE_ONLY_GEN_H

#include "code_gen.h"

class TypeOnlyGen : public CodeGen {
public:
    TypeOnlyGen(llvm::Type *t) {
        this->type = t;
    }

    llvm::Value *gen(const Generator &generator) override {
        return nullptr;
    }
};


#endif //LLVM_RUNNER_TYPE_ONLY_GEN_H
