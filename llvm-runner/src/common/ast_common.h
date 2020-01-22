//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_AST_COMMON_H
#define LLVM_RUNNER_AST_COMMON_H

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

#define AST_BASE_LIST() \
            AstValue, AstIntegerConstant, AstFloatConstant, AstBoolConstant, AstStringLiteral, /* Ast Value Nodes */ \
            AstLet, AstList, \
            AstDef, AstDefClass, AstPackage, \
            AstCommonNode, AstNode /* Ast Base Node */ \

#define AST_BASE(Type) \
    VisitableImpl<Type, AST_BASE_LIST()>\

#endif //LLVM_RUNNER_AST_COMMON_H
