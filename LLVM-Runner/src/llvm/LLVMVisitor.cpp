//
// Created by 刘丰恺 on 2018/8/3.
//

#include "LLVMVisitor.h"

LLVMVisitor::LLVMVisitor(const Pointer<AstNode> &root_node) : root_node(root_node), builder(the_context) {

}

Pointer<AstNode> LLVMVisitor::get_root_node() {
    return this->root_node;
}

Pointer<llvm::Value> LLVMVisitor::visit_ast_node(Pointer<AstNode> node) {
    return Visitor::visit_ast_node(node);
}

Pointer<llvm::Value> LLVMVisitor::visit_ast_leaf(Pointer<AstNode> node) {
    return Visitor::visit_ast_leaf(node);
}

Pointer<llvm::Value> LLVMVisitor::visit_binary_expr(Pointer<AstNode> node) {
    return Visitor::visit_binary_expr(node);
}

Pointer<llvm::Value> LLVMVisitor::visit_ast_list(Pointer<AstNode> node) {
    return Visitor::visit_ast_list(node);
}

Pointer<llvm::Value> LLVMVisitor::visit_number(Pointer<AstNode> node) {
    return Visitor::visit_number(node);
}

Pointer<llvm::Value> LLVMVisitor::visit(Pointer<AstNode> node) {
    return Visitor::visit(node);
}

Pointer<llvm::Value> LLVMVisitor::visit() {
    return Visitor::visit();
}
