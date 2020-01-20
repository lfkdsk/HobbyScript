//
// Created by 刘丰恺 on 19/1/2020.
//

#ifndef LLVM_RUNNER_CODE_GEN_VISITOR_H
#define LLVM_RUNNER_CODE_GEN_VISITOR_H

#include "ast/ast_nodes.hpp"
#include "visitor_base.h"

class CodeGenVisitor : BaseVisitor {
public:
    explicit CodeGenVisitor(AstContext *context);

public:
    void visit(const AstNode &node) override;

    void visit(const AstValue &node) override;

    void visit(const AstStringLiteral &node) override;

    void visit(const AstIntegerConstant &node) override;

    void visit(const AstBoolConstant &node) override;

    void visit(const AstFloatConstant &node) override;

    void visit(const AstLet &node) override;

    void visit(const AstList &node) override;

    void visit(const AstPackage &node) override;

private:
    AstContext *context = nullptr;
};


#endif //LLVM_RUNNER_CODE_GEN_VISITOR_H
