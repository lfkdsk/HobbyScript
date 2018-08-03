//
// Created by 刘丰恺 on 2018/8/1.
//

#ifndef LLVM_RUNNER_ASTVISITOR_H
#define LLVM_RUNNER_ASTVISITOR_H

#include <iostream>
#include "json.hpp"
#include "../ast/AstNodes.h"
#include "unitcpp/UnitTest++.h"

using json = nlohmann::json;
using string = std::string;
static const int BINARY_EXPR = 279;
static const int NUMBER_LITERAL = 270;
static const int AST_LEAF = 264;
static const int AST_LIST = 277;

class AstVisitor {
public:
    AstVisitor(const json &load_json);

    virtual ~AstVisitor();

    const json &get_json();

    Pointer<AstNode> visit_ast_node(const json &json_object);

    Pointer<AstNode> visit_ast_leaf(const json &json_object);

    Pointer<AstNode> visit_binary_expr(const json &json_object);

    Pointer<AstNode> visit_ast_list(const json &json_object);

    Pointer<AstNode> visit_number(const json &json_object);

    Pointer<AstNode> visit(const json &json_object);

    Pointer<AstNode> visit();

private:
    json load_json;
};


#endif //LLVM_RUNNER_ASTVISITOR_H
