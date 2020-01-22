//
// Created by 刘丰恺 on 21/1/2020.
//

#ifndef LLVM_RUNNER_GEN_COMMON_H
#define LLVM_RUNNER_GEN_COMMON_H

#include "visitor/visitor.h"

class CodeGen;

class TypeOnlyGen;

class ValueGen;

class LetGen;

#define GEN_BASE(Type) \
    VisitableImpl<\
            Type, \
            CodeGen, /* CodeGen Base Node */ \
            ValueGen, LetGen, TypeOnlyGen \
    >\


#endif //LLVM_RUNNER_GEN_COMMON_H
