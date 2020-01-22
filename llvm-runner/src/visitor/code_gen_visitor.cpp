//
// Created by 刘丰恺 on 19/1/2020.
//

#include "code_gen_visitor.h"

CodeGenVisitor::CodeGenVisitor(AstContext *context) : context(context) {}

CodeGenVisitor::CodeGenVisitor(CodeGenVisitor *parent) : parent_visitor(parent),
                                                         context(new AstContext(parent->context)) {}

void CodeGenVisitor::visit(AstNode &node) {
    set_codegen_result(node, new TypeOnlyGen(nullptr));
}

void CodeGenVisitor::visit(AstValue &node) {
    set_codegen_result(node, node.value ? node.codegen_result() : nullptr);
}

void CodeGenVisitor::visit(AstStringLiteral &node) {

}

void CodeGenVisitor::visit(AstIntegerConstant &node) {

}

void CodeGenVisitor::visit(AstBoolConstant &node) {

}

void CodeGenVisitor::visit(AstFloatConstant &node) {

}

void CodeGenVisitor::visit(AstLet &node) {
    if (!context) {
        return;
    }

    auto *value = context->find_symbol_value(node.name);
    if (!value) {
        throw create_runtime_error("could not find var: " + node.name);
    }

    if (!node.var_expr) {
        throw create_runtime_error("could not create var, because node's right expr is null.");
    }

    // code gen for right expr.
    auto *right = node.var_expr;
    this->visit(*right);
    auto *right_expr_gen = right->codegen_result();

    if (!right_expr_gen) {
        throw create_runtime_error("could not eval right expr " + node.name + " expr: ");
    }

    // trans right expr type to left type.
    if (!value->type) {
        value->type = right_expr_gen->type;
    }

    auto *let = context->find_symbol_value(node.name, true);
    // TODO: cal escape value.
    set_codegen_result(node, new LetGen(let, right_expr_gen));
}

void CodeGenVisitor::visit(AstList &node) {

}

void CodeGenVisitor::visit(AstPackage &node) {

}