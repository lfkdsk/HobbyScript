//
// Created by 刘丰恺 on 2018/8/2.
//

#include <rapidjson/document.h>
#include <gtest/gtest.h>
#include "ast/ast_nodes.hpp"
#include "visitor/AstVisitor.h"
#include "test_macro.h"

using json = rapidjson::Value;

TEST (AST, TestPrintAstLeaf) {
    document testJson;
    testJson.Parse(
            R"({"token":{"text":"+","lineNumber":1,"tag":264},"tag":264,"type":"ast_leaf"})");
    auto node_pointer = ast_visitor.visit(testJson);
    auto leaf = std::static_pointer_cast<ast_leaf>(node_pointer);
    CHECK_NON_NULL(leaf);
    ASSERT_EQ(true, leaf->get_token().HasMember("text"));
    ASSERT_EQ("+", leaf->get_text());
}

TEST (AST, TestPrintAstList) {
    document testJson;
    testJson.Parse(
            R"(
{
    "afterPoint":0,
    "children":[
        {
            "token":{
                "value":1,
                "lineNumber":1,
                "tag":270
            },
            "tag":270,
            "type":"NumberLiteral"
        },
        {
            "token":{
                "text":"+",
                "lineNumber":1,
                "tag":264
            },
            "tag":264,
            "type":"ast_leaf"
        },
        {
            "token":{
                "value":1111,
                "lineNumber":1,
                "tag":270
            },
            "tag":270,
            "type":"NumberLiteral"
        }
    ],
    "tag":277,
    "type":"ast_list"
}
            )");

    auto node_pointer = ast_visitor.visit(testJson);
    auto list = std::static_pointer_cast<ast_list>(node_pointer);
    CHECK_NON_NULL(list);
    ASSERT_EQ(3, list->get_children()->size());
}


TEST (AST, TestPrintNumeric1) {
    document testJson;
    testJson.Parse(
            R"({"token":{"value":1,"lineNumber":1,"tag":270},"tag":270,"type":"NumberLiteral"})");
    auto node_pointer = ast_visitor.visit(testJson);
    auto literal = std::static_pointer_cast<ast_number_literal>(node_pointer);
    CHECK_NON_NULL(literal);
    ASSERT_EQ(1, literal->get_value());
}

TEST (AST, TestPrintBinaryExpr) {
    document testJson;
    testJson.Parse(
            R"(
{
    "afterPoint":0,
    "children":[
        {
            "token":{
                "value":1,
                "lineNumber":1,
                "tag":270
            },
            "tag":270,
            "type":"NumberLiteral"
        },
        {
            "token":{
                "text":"+",
                "lineNumber":1,
                "tag":264
            },
            "tag":264,
            "type":"ast_leaf"
        },
        {
            "token":{
                "value":1111,
                "lineNumber":1,
                "tag":270
            },
            "tag":270,
            "type":"NumberLiteral"
        }
    ],
    "tag":279,
    "type":"ast_list"
}
            )");

    auto node_pointer = ast_visitor.visit(testJson);
    auto binaryExpr = std::static_pointer_cast<ast_binary_expr>(node_pointer);
    CHECK_NON_NULL(binaryExpr);
    ASSERT_EQ(3, binaryExpr->get_children()->size());

    auto literal = std::static_pointer_cast<ast_number_literal>(binaryExpr->get_left_node());
    CHECK_NON_NULL(literal);
    ASSERT_EQ(1, literal->get_value());

    auto leaf = std::static_pointer_cast<ast_leaf>(binaryExpr->get_mid_op());
    CHECK_NON_NULL(leaf);
    ASSERT_EQ("+", leaf->get_text());

    auto literal2 = std::static_pointer_cast<ast_number_literal>(binaryExpr->get_right_node());
    CHECK_NON_NULL(literal2);
    ASSERT_EQ(1111, literal2->get_value());
}

TEST (AST, FunctionDefTest1) {
    document testJson;
    testJson.Parse(
            R"(
{
    "afterPoint":0,
    "children":[
        {
            "token":{
                "text":"fuckTest",
                "lineNumber":1,
                "tag":264
            },
            "tag":264,
            "type":"ast_leaf"
        },
        {
            "afterPoint":0,
            "children":[

            ],
            "tag":283,
            "type":"ParameterList"
        },
        {
            "afterPoint":0,
            "children":[
                {
                    "afterPoint":0,
                    "children":[
                        {
                            "token":{
                                "literal":"lfkdsssssssss",
                                "lineNumber":2,
                                "tag":276
                            },
                            "tag":276,
                            "type":"StringLiteral"
                        }
                    ],
                    "tag":296,
                    "type":"ReturnStmt"
                }
            ],
            "tag":278,
            "type":"DefBlockStmt"
        }
    ],
    "tag":280,
    "type":"FuncStmt"
}
            )");

    auto node_pointer = ast_visitor.visit(testJson);
    auto func_stmt = std::static_pointer_cast<FuncStmt>(node_pointer);
    CHECK_NON_NULL(func_stmt);
    ASSERT_EQ(3, func_stmt->get_children()->size());

    auto name = std::static_pointer_cast<ast_leaf>(func_stmt->name());
    CHECK_NON_NULL(name);
    ASSERT_EQ("fuckTest", name->

            get_text()

    );

    auto params_list = func_stmt->params_list();
    CHECK_NON_NULL(params_list);
    ASSERT_EQ(0, params_list->get_children()->size());

    auto def_block_stmt = std::static_pointer_cast<DefBlockStmt>(func_stmt->def_blocks());
    CHECK_NON_NULL(def_block_stmt);
    ASSERT_EQ(1, def_block_stmt->get_children()->size());
}