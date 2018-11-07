//
// Created by 刘丰恺 on 2018/8/1.
//

#ifndef LLVM_RUNNER_ASTVISITOR_H
#define LLVM_RUNNER_ASTVISITOR_H

#include <iostream>
#include "ast/ast_nodes.hpp"
#include "rapidjson/document.h"
#include "Visitor.h"

static const int BINARY_EXPR = 279;
static const int NUMBER_LITERAL = 270;
static const int STRING_LITERAL = 276;
static const int AST_LEAF = 264;
static const int AST_LIST = 277;
static const int DEF_BLOCK = 278;
static const int FUNCTION = 280;
static const int PARAMS_LIST = 283;

class AstVisitor : public Visitor<pointer<ast_node>, rapidjson::Value &> {
public:
    AstVisitor();

    virtual ~AstVisitor();

    pointer<ast_node> visit_ast_node(rapidjson::Value &node) override;

    pointer<ast_node> visit_ast_leaf(rapidjson::Value &node) override;

    pointer<ast_node> visit_binary_expr(rapidjson::Value &node) override;

    pointer<ast_node> visit_ast_list(rapidjson::Value &node) override;

    pointer<ast_node> visit_fun_stmt(rapidjson::Value &node) override;

    pointer<ast_node> visit_def_block(rapidjson::Value &node) override;

    pointer<ast_node> visit_number(rapidjson::Value &node) override;

    pointer<ast_node> visit_string(rapidjson::Value &node) override;

    pointer<ast_node> visit(rapidjson::Value &node) override;

    pointer<ast_node> visit() override;
};

#endif //LLVM_RUNNER_ASTVISITOR_H

#ifndef DEFAULT_AST_VISITOR
#define DEFAULT_AST_VISITOR

static auto ast_visitor = AstVisitor();


#endif // DEFAULT_AST_VISITOR