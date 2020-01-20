//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_AST_COMMON_H
#define LLVM_RUNNER_AST_COMMON_H

/* Type && Context */
class AstType;

class AstContext;

/* Code Gen */
class CodeGen;

/* AstNodes */
class AstNode;

class AstValue;

class AstIntegerConstant;

class AstFloatConstant;

class AstBoolConstant;

class AstStringLiteral;

class AstLet;

class AstList;

class AstPackage;

#define AST_BASE(Type) \
    VisitableImpl<\
            Type, \
            AstNode, /* Ast Base Node */ \
            AstValue, AstIntegerConstant, AstFloatConstant, AstBoolConstant, AstStringLiteral, /* Ast Value Nodes */ \
            AstLet, AstList, AstPackage \
    >\

#endif //LLVM_RUNNER_AST_COMMON_H
