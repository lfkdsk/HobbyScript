//
// Created by 刘丰恺 on 23/1/2020.
//

#ifndef LLVM_RUNNER_DEF_GEN_H
#define LLVM_RUNNER_DEF_GEN_H

#include "code_gen.h"

class DefGen : public CodeGen, public GEN_BASE(DefGen) {
public:
    DefGen(const QString &n, llvm::Type *t, CodeGen *value = nullptr, int array_size = 1) {}

public:
    QString name;

private:
    CodeGen *value = nullptr;
    bool is_class = false;
    int array_size = 0;
};


#endif //LLVM_RUNNER_DEF_GEN_H
