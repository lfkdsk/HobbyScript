//
// Created by 刘丰恺 on 19/1/2020.
//

#ifndef LLVM_RUNNER_CODE_GEN_VISITOR_H
#define LLVM_RUNNER_CODE_GEN_VISITOR_H

#include "ast/ast_nodes.hpp"
#include "gen/code_gens.hpp"
#include "visitor_base.h"

class CodeGenVisitor : public BaseVisitor {
public:
    explicit CodeGenVisitor(AstContext *context);

public:
    void visit(AstNode &node) override;

    void visit(AstValue &node) override;

    void visit(AstStringLiteral &node) override;

    void visit(AstIntegerConstant &node) override;

    void visit(AstBoolConstant &node) override;

    void visit(AstFloatConstant &node) override;

    void visit(AstLet &node) override;

    void visit(AstList &node) override;

    void visit(AstPackage &node) override;

private:
    AstContext *context = nullptr;
private:
    inline static void set_codegen_result(AstNode &node, CodeGen *gen) {
        node.set_codegen_result(gen);
    }
};


#endif //LLVM_RUNNER_CODE_GEN_VISITOR_H
