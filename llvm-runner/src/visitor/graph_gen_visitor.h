//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_GRAPH_GEN_VISITOR_H
#define LLVM_RUNNER_GRAPH_GEN_VISITOR_H

#include "visitor_base.h"
#include "ast/ast_nodes.hpp"
#include "common/common.h"

class GraphGenVisitor : public BaseVisitor {
public:
    explicit GraphGenVisitor(std::ostream &os = std::cout) : os(os) {};

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
    std::ostream &os;

    void to_graph(const QString &name, AstNode &node);

    void to_dot_label(const QString &v, const QString &shape, AstNode &node);

    void to_dot_point_to(AstNode &from, AstNode &to, bool array);

    void to_dot_point_to(AstNode &from, const QVector<AstNode *> &nodes, bool array);
};

#endif //LLVM_RUNNER_GRAPH_GEN_VISITOR_H
