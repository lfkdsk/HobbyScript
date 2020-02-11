//
// Created by 刘丰恺 on 10/2/2020.
//

#ifndef LLVM_RUNNER_NEW_GEN_H
#define LLVM_RUNNER_NEW_GEN_H

#include "gen/code_gen.h"
#include "common/common.h"
#include "common/llvm_common.h"

class NewGen : public CodeGen, public GEN_BASE(NewGen) {
public:
    explicit NewGen(llvm::Type *type = nullptr) : CodeGen(type) {
        this->runtime_type = NewGenTy;
    };

public:
    CodeGen *constructor = nullptr;
    CodeGen *finalizer = nullptr;
    QString name;
};


#endif //LLVM_RUNNER_NEW_GEN_H
