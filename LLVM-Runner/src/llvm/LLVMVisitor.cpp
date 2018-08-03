//
// Created by 刘丰恺 on 2018/8/3.
//

#include "LLVMVisitor.h"

LLVMVisitor::LLVMVisitor(const Pointer<AstNode> &root_node) : root_node(root_node), builder(the_context) {

}

Pointer<AstNode> LLVMVisitor::get_root_node() {
    return this->root_node;
}

Pointer<Value> LLVMVisitor::visit_number_literial(Pointer<NumberLiteral> node) {
    return Pointer<Value>(ConstantFP::get(the_context, APFloat(node->getValue())));
}

Pointer<Value> LLVMVisitor::visit_binary_expr(Pointer<BinaryExpr> node) {

}

Pointer<Value> LLVMVisitor::visit_ast_leaf(Pointer<AstLeaf> node) {

}
