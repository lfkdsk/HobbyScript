//
// Created by 刘丰恺 on 2018/8/1.
//

#ifndef LLVM_RUNNER_ASTVISITOR_H
#define LLVM_RUNNER_ASTVISITOR_H

#include <iostream>
#include "json.hpp"
#include "rapidjson/document.h"
#include "ast/ast_nodes.h"
#include "Visitor.h"

static const int BINARY_EXPR = 279;
static const int NUMBER_LITERAL = 270;
static const int STRING_LITERAL = 276;
static const int AST_LEAF = 264;
static const int AST_LIST = 277;
static const int DEF_BLOCK = 278;
static const int FUNCTION = 280;
static const int PARAMS_LIST = 283;

class AstVisitor : public Visitor<pointer<ast_node>, const rapidjson::Value &> {
public:
    AstVisitor();

    virtual ~AstVisitor();

    pointer<ast_node> visit_ast_node(const rapidjson::Value &node) override;

    pointer<ast_node> visit_ast_leaf(const rapidjson::Value &node) override;

    pointer<ast_node> visit_binary_expr(const rapidjson::Value &node) override;

    pointer<ast_node> visit_ast_list(const rapidjson::Value &node) override;

    pointer<ast_node> visit_fun_stmt(const rapidjson::Value &node) override;

    pointer<ast_node> visit_def_block(const rapidjson::Value &node) override;

    pointer<ast_node> visit_number(const rapidjson::Value &node) override;

    pointer<ast_node> visit_string(const rapidjson::Value &node) override;

    pointer<ast_node> visit(const rapidjson::Value &node) override;

    pointer<ast_node> visit() override;
};

#endif //LLVM_RUNNER_ASTVISITOR_H

#ifndef DEFAULT_AST_VISITOR
#define DEFAULT_AST_VISITOR

static auto ast_visitor = AstVisitor();


#endif // DEFAULT_AST_VISITOR