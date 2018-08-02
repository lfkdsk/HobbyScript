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
using AstNodePointer = std::shared_ptr<AstNode>;

static const int BINARY_EXPR = 279;
static const int NUMBER_LITERAL = 270;
static const int AST_LEAF = 264;

class AstVisitor {
public:
    AstVisitor(const json& load_json);
    virtual ~AstVisitor();
    const json& get_json();
    AstNodePointer visit_ast_node(const json& json_object);
    AstNodePointer visit_ast_leaf(const json& json_object);
    AstNodePointer visit_binary_expr(const json& json_object);
    AstNodePointer visit_ast_list(const json& json_object);
    AstNodePointer visit_number(const json& json_object);
    AstNodePointer visit(const json& json_object);
    AstNodePointer visit();
private:
    json load_json;
};


#endif //LLVM_RUNNER_ASTVISITOR_H
