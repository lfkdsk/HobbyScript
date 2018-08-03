//
// Created by 刘丰恺 on 2018/8/3.
//

#include "LLVMCodeGenVisitor.h"

LLVMCodeGenVisitor::LLVMCodeGenVisitor(const Pointer<AstNode> &root_node) : root_node(root_node), builder(the_context) {

}

Pointer<AstNode> LLVMCodeGenVisitor::get_root_node() {
    return this->root_node;
}

ValuePointer LLVMCodeGenVisitor::visit_ast_node(Pointer<AstNode> node) {

}

ValuePointer LLVMCodeGenVisitor::visit_ast_leaf(Pointer<AstNode> node) {
}

ValuePointer LLVMCodeGenVisitor::visit_binary_expr(Pointer<AstNode> node) {
}

ValuePointer LLVMCodeGenVisitor::visit_ast_list(Pointer<AstNode> node) {
}

ValuePointer LLVMCodeGenVisitor::visit_number(Pointer<AstNode> node) {
    auto number = Cast<NumberLiteral, AstNode>(node);
    return ConstantFP::get(the_context, APFloat(number->getValue()));
}

ValuePointer LLVMCodeGenVisitor::visit(Pointer<AstNode> node) {
}

ValuePointer LLVMCodeGenVisitor::visit() {
}
