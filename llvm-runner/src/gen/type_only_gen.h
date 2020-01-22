//
// Created by 刘丰恺 on 19/1/2020.
//

#ifndef LLVM_RUNNER_TYPE_ONLY_GEN_H
#define LLVM_RUNNER_TYPE_ONLY_GEN_H

#include "code_gen.h"

class TypeOnlyGen : public CodeGen, public GEN_BASE(TypeOnlyGen) {
public:
    explicit TypeOnlyGen(llvm::Type *t) : CodeGen(t) {};
};


#endif //LLVM_RUNNER_TYPE_ONLY_GEN_H
