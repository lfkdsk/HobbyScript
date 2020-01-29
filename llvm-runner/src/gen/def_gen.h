//
// Created by 刘丰恺 on 23/1/2020.
//

#ifndef LLVM_RUNNER_DEF_GEN_H
#define LLVM_RUNNER_DEF_GEN_H

#include <utility>

#include "code_gen.h"

class DefGen : public CodeGen, public GEN_BASE(DefGen) {
public:
    DefGen(QString n, llvm::Type *t, CodeGen *value = nullptr, int array_size = 1)
            : name(std::move(n)), array_size(array_size), gen_value(value) {
        this->type = t;
        this->runtime_type = DefGenTy;
    }

public:
    QString name;
    CodeGen *gen_value = nullptr;
    bool is_class = false;
    int array_size = 0;
};


#endif //LLVM_RUNNER_DEF_GEN_H
