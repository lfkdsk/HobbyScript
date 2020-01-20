//
// Created by 刘丰恺 on 19/1/2020.
//

#include "code_gen_visitor.h"

CodeGenVisitor::CodeGenVisitor(AstContext *context) : context(context) {}

void CodeGenVisitor::visit(AstNode &node) {
    this->set_codegen_result(node, new TypeOnlyGen(nullptr));
}

void CodeGenVisitor::visit(AstValue &node) {

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
