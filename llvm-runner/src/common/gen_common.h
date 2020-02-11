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

class DefGen;

class StringLiteGen;

class CallGen;

class NewGen;

enum GenType {
    CodeGenTy,
    TypeOnlyTy,
    ValueGenTy,
    LetGenTy,
    DefGenTy,
    StringLiteGenTy,
    CallGenTy,
    NewGenTy,
};

#define GEN_BASE(Type) \
    VisitableImpl<\
            Type, \
            CodeGen, /* CodeGen Base Node */ \
            ValueGen, LetGen, TypeOnlyGen, \
            DefGen, StringLiteGen, NewGen \
    >\

#define GEN_TYPE_AUTO_DOWNCAST(node, visitor) \
    switch (node->runtime_type) { \
        case DefGenTy: { \
            visitor->visit(*dynamic_cast<DefGen *>(node)); \
            break; \
        } \
        case NewGenTy: { \
            visitor->visit(*dynamic_cast<NewGen *>(node)); \
            break; \
        } \
        case CallGenTy: { \
            visitor->visit(*dynamic_cast<CallGen *>(node)); \
            break; \
        } \
        case StringLiteGenTy: { \
            visitor->visit(*dynamic_cast<StringLiteGen *>(node)); \
            break; \
        } \
    } \


#endif //LLVM_RUNNER_GEN_COMMON_H
