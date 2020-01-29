//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_GRAPH_GEN_VISITOR_H
#define LLVM_RUNNER_GRAPH_GEN_VISITOR_H

#include "visitor_base.h"
#include "ast/ast_nodes.hpp"
#include "common/common.h"

/**
 * Convert Ast Node => Dot Graph
 */
class GraphGenVisitor : public AstBaseVisitor {
public:
    explicit GraphGenVisitor(std::ostream &os = std::cout, bool with_global_index = false) :
            os(os), with_global_index(with_global_index) {};
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

    void visit(AstDef &node) override;

    void visit(AstDefClass &node) override;

private:
    std::ostream &os;
    const bool with_global_index;
private:
    void to_graph(const QString &name, AstNode &node);

    void to_dot_label(AstNode &node, const QString &v, const QString &shape = "");

    void to_dot_point_to(AstNode &from, AstNode &to, bool array = false);

    void to_dot_point_to(AstNode &from, const QVector<AstNode *> &nodes, bool array);

    std::string get_node_index(AstNode &node);

private:
    long node_total_index = 0;
};


#endif //LLVM_RUNNER_GRAPH_GEN_VISITOR_H
