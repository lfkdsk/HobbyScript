//
// Created by 刘丰恺 on 20/1/2020.
//

#include "graph_gen_visitor.h"

void GraphGenVisitor::visit(AstNode &node) {
    this->to_graph(node.name, node);
}

void GraphGenVisitor::visit(AstValue &node) {
    this->visit(dynamic_cast<AstNode &>(node));
}

void GraphGenVisitor::visit(AstStringLiteral &node) {

}

void GraphGenVisitor::visit(AstIntegerConstant &node) {

}

void GraphGenVisitor::visit(AstBoolConstant &node) {

}

void GraphGenVisitor::visit(AstFloatConstant &node) {

}

void GraphGenVisitor::visit(AstLet &node) {
    this->to_dot_label(node, node.name + "=");
    this->to_dot_point_to(node, *node.var_expr);
}

void GraphGenVisitor::visit(AstList &node) {

}

void GraphGenVisitor::visit(AstPackage &node) {

}

void GraphGenVisitor::visit(AstDef &node) {

}

void GraphGenVisitor::visit(AstDefClass &node) {

}

void GraphGenVisitor::to_graph(const QString &name, AstNode &node) {
    this->to_dot_label(node, name);
}

void GraphGenVisitor::to_dot_label(
        AstNode &node,
        const QString &v,
        const QString &shape
) {
    std::string sz = v.toUtf8().toStdString();
    while (sz.find('\r') != -1)
        sz.erase(sz.find('\r'));
    while (sz.find('\n') != -1)
        sz.erase(sz.find('\n'));
    while (sz.find('\0') != -1)
        sz.erase(sz.find('\0'));

    os << get_node_index(node) << "[label=\"" + sz + "\" ";
    if (!shape.isEmpty()) {
        os << "shape=" << shape.toUtf8().toStdString();
    }
    os << "]" << std::endl;
}

void GraphGenVisitor::to_dot_point_to(AstNode &from, AstNode &to, bool array) {
    os << get_node_index(from) << " -> " << get_node_index(to) << std::endl;
    this->visit(from);
}

void GraphGenVisitor::to_dot_point_to(AstNode &from, const QVector<AstNode *> &nodes, bool array) {
    for (auto item : nodes) {
        to_dot_point_to(from, *item, array);
    }
}

std::string GraphGenVisitor::get_node_index(AstNode &node) {
    return "dot" + (this->with_global_index ? QString::number(++node_total_index).toUtf8().toStdString() : node.node_id_str);
}