//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_BASE_VISITOR_H
#define LLVM_RUNNER_BASE_VISITOR_H

#include "utils/ast_common.h"

class BaseVisitor {
public:
    // base
    virtual void visit(AstNode &node) = 0;

    // constant value.
    virtual void visit(AstValue &node) = 0;

    virtual void visit(AstStringLiteral &node) = 0;

    virtual void visit(AstIntegerConstant &node) = 0;

    virtual void visit(AstBoolConstant &node) = 0;

    virtual void visit(AstFloatConstant &node) = 0;

    // package.
    virtual void visit(AstLet &node) = 0;

    virtual void visit(AstList &node) = 0;

    virtual void visit(AstPackage &node) = 0;
};

#endif //LLVM_RUNNER_BASE_VISITOR_H
