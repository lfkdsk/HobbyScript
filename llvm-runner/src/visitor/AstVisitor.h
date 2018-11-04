//
// Created by 刘丰恺 on 2018/8/1.
//

#ifndef LLVM_RUNNER_ASTVISITOR_H
#define LLVM_RUNNER_ASTVISITOR_H

#include <iostream>
#include "json.hpp"
#include "../ast/AstNodes.h"
#include "Visitor.h"
#include "unitcpp/UnitTest++.h"

using json = nlohmann::json;
using string = std::string;
static const int BINARY_EXPR = 279;
static const int NUMBER_LITERAL = 270;
static const int STRING_LITERAL = 276;
static const int AST_LEAF = 264;
static const int AST_LIST = 277;
static const int DEF_BLOCK = 278;
static const int FUNCTION = 280;
static const int PARAMS_LIST = 283;

class AstVisitor : public Visitor<Pointer<AstNode>, const json &> {
public:
    AstVisitor(const json &load_json);

    virtual ~AstVisitor();

    const json &get_json();

    Pointer<AstNode> visit_ast_node(const json &node) override;

    Pointer<AstNode> visit_ast_leaf(const json &node) override;

    Pointer<AstNode> visit_binary_expr(const json &node) override;

    Pointer<AstNode> visit_ast_list(const json &node) override;

    Pointer<AstNode> visit_fun_stmt(const json &node) override;

    Pointer<AstNode> visit_def_block(const json &node) override;

    Pointer<AstNode> visit_number(const json &node) override;

    Pointer<AstNode> visit_string(const json &node) override;

    Pointer<AstNode> visit(const json &node) override;

    Pointer<AstNode> visit() override;

protected:
    Pointer<AstNodeList> node_to_list(jsonVector &children);

private:
    json load_json;
};


#endif //LLVM_RUNNER_ASTVISITOR_H
