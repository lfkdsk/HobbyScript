//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_GRAPH_GEN_VISITOR_H
#define LLVM_RUNNER_GRAPH_GEN_VISITOR_H

#include "visitor_base.h"

class GraphGenVisitor : public BaseVisitor {
public:
    explicit GraphGenVisitor();

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
};


#endif //LLVM_RUNNER_GRAPH_GEN_VISITOR_H
