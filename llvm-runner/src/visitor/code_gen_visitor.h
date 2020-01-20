//
// Created by 刘丰恺 on 19/1/2020.
//

#ifndef LLVM_RUNNER_CODE_GEN_VISITOR_H
#define LLVM_RUNNER_CODE_GEN_VISITOR_H

#include "ast/ast_nodes.hpp"

class CodeGenVisitor {
public:
    explicit CodeGenVisitor(AstContext *context);

public:
    // base
    void visit(const AstNode &node);

    // constant value.
    void visit(const AstValue &node);

    void visit(const AstStringLiteral &node);

    void visit(const AstIntegerConstant &node);

    void visit(const AstBoolConstant &node);

    void visit(const AstFloatConstant &node);

    // package.
    void visit(const AstLet &node);

    void visit(const AstList &node);

    void visit(const AstPackage &node);

private:
    AstContext *context = nullptr;
};


#endif //LLVM_RUNNER_CODE_GEN_VISITOR_H
