//
// Created by 刘丰恺 on 21/1/2020.
//

#ifndef LLVM_RUNNER_LET_GEN_H
#define LLVM_RUNNER_LET_GEN_H

#include "code_gen.h"

class LetGen : public CodeGen, public GEN_BASE(LetGen) {
public:
    explicit LetGen(CodeGen *left, CodeGen *right) : left(left), right(right) {};

public:
    CodeGen *left = nullptr;
    CodeGen *right = nullptr;
};


#endif //LLVM_RUNNER_LET_GEN_H
