//
// Created by 刘丰恺 on 23/1/2020.
//

#ifndef LLVM_RUNNER_TYPE_COMMON_H
#define LLVM_RUNNER_TYPE_COMMON_H

#include "visitor/visitor.h"

class AstType;

class AutoType;

class ClassType;

class IntegerType;

#define TYPE_BASE_LIST() \
      AstType, /* AstType Base Node */ \
      AutoType, ClassType, IntegerType \

#define TYPE_BASE(Type) VisitableImpl<Type, TYPE_BASE_LIST()>


#endif //LLVM_RUNNER_TYPE_COMMON_H
