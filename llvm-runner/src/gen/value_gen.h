//
// Created by 刘丰恺 on 21/1/2020.
//

#ifndef LLVM_RUNNER_VALUE_GEN_H
#define LLVM_RUNNER_VALUE_GEN_H

#include "code_gen.h"

class ValueGen : public CodeGen, public GEN_BASE(ValueGen) {
public:
    explicit ValueGen(llvm::Value *v) : CodeGen(v) {
        this->runtime_type = ValueGenTy;
    }
};


#endif //LLVM_RUNNER_VALUE_GEN_H
