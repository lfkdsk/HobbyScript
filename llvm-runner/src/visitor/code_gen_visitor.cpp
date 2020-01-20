//
// Created by 刘丰恺 on 19/1/2020.
//

#include "code_gen_visitor.h"

CodeGenVisitor::CodeGenVisitor(AstContext *context) : context(context) {}

void CodeGenVisitor::visit(const AstNode &node) {

}

void CodeGenVisitor::visit(const AstValue &node) {

}

void CodeGenVisitor::visit(const AstStringLiteral &node) {

}

void CodeGenVisitor::visit(const AstIntegerConstant &node) {

}

void CodeGenVisitor::visit(const AstBoolConstant &node) {

}

void CodeGenVisitor::visit(const AstFloatConstant &node) {

}

void CodeGenVisitor::visit(const AstLet &node) {

}

void CodeGenVisitor::visit(const AstList &node) {

}

void CodeGenVisitor::visit(const AstPackage &node) {

}
