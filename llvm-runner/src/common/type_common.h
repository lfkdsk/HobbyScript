//
// Created by 刘丰恺 on 23/1/2020.
//

#ifndef LLVM_RUNNER_TYPE_COMMON_H
#define LLVM_RUNNER_TYPE_COMMON_H

#include "visitor/visitor.h"
#include "llvm_type.h"

class AstType;

class AutoType;

class ClassType;

class IntegerType;

class LLVMStructType;

class StringType;

#define TYPE_BASE_LIST() \
      AstType, /* AstType Base Node */ \
      AutoType, ClassType, IntegerType, LLVMStructType, StringType \

#define TYPE_BASE(Type) VisitableImpl<Type, TYPE_BASE_LIST()>

#define TYPE_TYPE_AUTO_DOWNCAST(node, visitor) \
    switch (node->get_type_id()) { \
        case IntegerTyID: { \
            visitor->visit(*dynamic_cast<IntegerType *>(node)); \
            break; \
        } \
        case CharactersTyId: { \
            visitor->visit(*dynamic_cast<StringType *>(node)); \
            break; \
        } \
    } \


#endif //LLVM_RUNNER_TYPE_COMMON_H
