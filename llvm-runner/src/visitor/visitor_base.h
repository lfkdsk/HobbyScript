//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_BASE_VISITOR_H
#define LLVM_RUNNER_BASE_VISITOR_H

#include "utils/ast_common.h"

class BaseVisitor {
public:
    // base
    virtual void visit(const AstNode &node) = 0;

    // constant value.
    virtual void visit(const AstValue &node) = 0;

    virtual void visit(const AstStringLiteral &node) = 0;

    virtual void visit(const AstIntegerConstant &node) = 0;

    virtual void visit(const AstBoolConstant &node) = 0;

    virtual void visit(const AstFloatConstant &node) = 0;

    // package.
    virtual void visit(const AstLet &node) = 0;

    virtual void visit(const AstList &node) = 0;

    virtual void visit(const AstPackage &node) = 0;
};

#endif //LLVM_RUNNER_BASE_VISITOR_H
