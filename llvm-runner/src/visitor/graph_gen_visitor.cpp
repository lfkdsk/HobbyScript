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

}

void GraphGenVisitor::visit(AstList &node) {

}

void GraphGenVisitor::visit(AstPackage &node) {

}

void GraphGenVisitor::to_graph(const QString &name, AstNode &node) {
    this->to_dot_label(name, "", node);
}

void GraphGenVisitor::to_dot_label(
        const QString &v,
        const QString &shape,
        AstNode &node
) {
    std::string sz = v.toStdString();
    while (sz.find('\r') != -1)
        sz.erase(sz.find('\r'));
    while (sz.find('\n') != -1)
        sz.erase(sz.find('\n'));
    while (sz.find('\0') != -1)
        sz.erase(sz.find('\0'));

    os << node.node_id_str << "[label=\"" + sz + "\" ";
    if (!shape.isEmpty())
        os << "shape=" << shape.toStdString();
    os << "]" << std::endl;
}

void GraphGenVisitor::to_dot_point_to(AstNode &from, AstNode &to, bool array) {
    os << from.node_id_str << " -> " << to.node_id_str << std::endl;
    this->visit(from);
}

void GraphGenVisitor::to_dot_point_to(AstNode &from, const QVector<AstNode *> &nodes, bool array) {
    for (auto item : nodes) {
        to_dot_point_to(from, *item, array);
    }
}