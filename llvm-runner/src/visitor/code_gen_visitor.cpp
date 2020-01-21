//
// Created by 刘丰恺 on 19/1/2020.
//

#include "code_gen_visitor.h"

CodeGenVisitor::CodeGenVisitor(AstContext *context) : context(context) {}

CodeGenVisitor::CodeGenVisitor(CodeGenVisitor *parent) : parent(parent), context(new AstContext(parent->context)) {}

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

}

void CodeGenVisitor::visit(AstList &node) {

}

void CodeGenVisitor::visit(AstPackage &node) {

}