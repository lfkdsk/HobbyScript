//
// Created by 刘丰恺 on 2018/8/1.
//

#ifndef LLVM_RUNNER_ASTVISITOR_H
#define LLVM_RUNNER_ASTVISITOR_H

#include <iostream>
#include "json.hpp"
#include "ast/ast_nodes.h"
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

class AstVisitor : public Visitor<pointer<ast_node>, const json &> {
public:
    AstVisitor(const json &load_json);

    virtual ~AstVisitor();

    const json &get_json();

    pointer<ast_node> visit_ast_node(const json &node) override;

    pointer<ast_node> visit_ast_leaf(const json &node) override;

    pointer<ast_node> visit_binary_expr(const json &node) override;

    pointer<ast_node> visit_ast_list(const json &node) override;

    pointer<ast_node> visit_fun_stmt(const json &node) override;

    pointer<ast_node> visit_def_block(const json &node) override;

    pointer<ast_node> visit_number(const json &node) override;

    pointer<ast_node> visit_string(const json &node) override;

    pointer<ast_node> visit(const json &node) override;

    pointer<ast_node> visit() override;

protected:
    pointer<ast_node_list> node_to_list(json_vector &children);

private:
    json load_json;
};


#endif //LLVM_RUNNER_ASTVISITOR_H
