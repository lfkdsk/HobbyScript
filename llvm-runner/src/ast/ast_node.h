//
// Created by 刘丰恺 on 16/1/2020.
//

#ifndef LLVM_RUNNER_AST_NODE_H
#define LLVM_RUNNER_AST_NODE_H

#include <string>
#include <utility>
#include "ast_context.h"
#include "gen/code_gen.h"
#include "utils/common.h"
#include "visitor/visitor.h"

extern int yylineno;

/* Type && Context */
class AstType;

class AstContext;

/* Code Gen */
class CodeGen;

/* AstNodes */
class AstNode;
class AstValue; class AstIntegerConstant; class AstFloatConstant; class AstBoolConstant; class AstStringLiteral;
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


class AstNode : public AST_BASE(AstNode) {
public:
    AstNode(QString n = QString()) : name(std::move(n)) {
        this->line_num = yylineno;
    };

    virtual ~AstNode() {}

public:
    QString name;
    int line_num;
};


#endif //LLVM_RUNNER_AST_NODE_H
