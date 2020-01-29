//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_AST_COMMON_H
#define LLVM_RUNNER_AST_COMMON_H

#include "common.h"

/* Type && Context */
class AstContext;

/* Code Gen */
class CodeGen;

/* AstNodes */
class AstNode;

class AstCommonNode;

class AstValue;

class AstIntegerConstant;

class AstFloatConstant;

class AstBoolConstant;

class AstStringLiteral;

class AstLet;

class AstList;

class AstDef;

class AstDefClass;

class AstPackage;

enum AstRuntimeType {
    AstNodeTy,
    AstValueTy,
    AstIntegerConstantTy,
    AstFloatConstantTy,
    AstBoolConstantTy,
    AstStringLiteralTy,
    AstLetTy,
    AstListTy,
    AstDefTy,
    AstDefClassTy,
    AstPackageTy
};

inline QString tag(AstRuntimeType type) {
    switch (type) {
        case AstNodeTy:
            return "AstNode";
        case AstValueTy:
            return "AstValue";
        case AstIntegerConstantTy:
            return "AstIntegerConstant";
        case AstFloatConstantTy:
            return "AstFloatConstant";
        case AstBoolConstantTy:
            return "AstBoolConstant";
        case AstStringLiteralTy:
            return "AstStringLiteral";
        case AstLetTy:
            return "AstLet";
        case AstListTy:
            return "AstList";
        case AstDefTy:
            return "AstDef";
        case AstDefClassTy:
            return "AstDefClass";
        case AstPackageTy:
            return "AstPackage";
    }
}

#define AST_BASE_LIST() \
            AstValue, AstIntegerConstant, AstFloatConstant, AstBoolConstant, AstStringLiteral, /* Ast Value Nodes */ \
            AstLet, AstList, \
            AstDef, AstDefClass, AstPackage, \
            AstCommonNode, AstNode /* Ast Base Node */ \

#define AST_BASE(Type) \
    VisitableImpl<Type, AST_BASE_LIST()>\


#define AST_TYPE_AUTO_DOWNCAST(node, visitor) \
    switch (node->runtime_type) { \
        case AstDefTy: { \
            visitor->visit(*dynamic_cast<AstDef *>(node)); \
            break; \
        } \
        case AstIntegerConstantTy: { \
            visitor->visit(*dynamic_cast<AstIntegerConstant *>(node)); \
            break; \
        } \
    } \

#endif //LLVM_RUNNER_AST_COMMON_H
