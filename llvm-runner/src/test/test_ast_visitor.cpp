//
// Created by 刘丰恺 on 2018/8/2.
//

#include "unitcpp/UnitTest++.h"
#include "visitor/AstVisitor.h"
#include "utils/JsonUtils.h"

using json = rapidjson::Value;

SUITE (TEST_FOR_COMMON_AST_NODE) {
    TEST (TestPrintAstLeaf) {
        document testJson;
        testJson.Parse(
                R"({"token":{"text":"+","lineNumber":1,"tag":264},"tag":264,"type":"ast_leaf"})");
        auto node_pointer = ast_visitor.visit(testJson);
        auto leaf = std::static_pointer_cast<ast_leaf>(node_pointer);
        UNITTEST_CHECK(leaf);
        UNITTEST_CHECK_EQUAL(true, leaf->get_token().HasMember("text"));
        UNITTEST_CHECK_EQUAL("+", leaf->get_text());
    }

    TEST (TestPrintAstList) {
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
        UNITTEST_CHECK(list);
        UNITTEST_CHECK_EQUAL(3, list->get_children()->size());
    }

}

TEST (TestPrintNumeric1) {
    document testJson;
    testJson.Parse(
            R"({"token":{"value":1,"lineNumber":1,"tag":270},"tag":270,"type":"NumberLiteral"})");
    auto node_pointer = ast_visitor.visit(testJson);
    auto literal = std::static_pointer_cast<ast_number_literal>(node_pointer);
    UNITTEST_CHECK(literal);
    UNITTEST_CHECK_EQUAL(1, literal->get_value());
}

TEST (TestPrintBinaryExpr) {
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
    UNITTEST_CHECK(binaryExpr);
    UNITTEST_CHECK_EQUAL(3, binaryExpr->get_children()->size());

    auto literal = std::static_pointer_cast<ast_number_literal>(binaryExpr->get_left_node());
    UNITTEST_CHECK(literal);
    UNITTEST_CHECK_EQUAL(1, literal->get_value());

    auto leaf = std::static_pointer_cast<ast_leaf>(binaryExpr->get_mid_op());
    UNITTEST_CHECK(leaf);
    UNITTEST_CHECK_EQUAL("+", leaf->get_text());

    auto literal2 = std::static_pointer_cast<ast_number_literal>(binaryExpr->get_right_node());
    UNITTEST_CHECK(literal2);
    UNITTEST_CHECK_EQUAL(1111, literal2->get_value());
}

TEST (FunctionDefTest1) {
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
    UNITTEST_CHECK(func_stmt);
    UNITTEST_CHECK_EQUAL(3, func_stmt->get_children()->size());

    auto name = std::static_pointer_cast<ast_leaf>(func_stmt->name());
    UNITTEST_CHECK(name);
    UNITTEST_CHECK_EQUAL("fuckTest", name->get_text());

    auto params_list = func_stmt->params_list();
    UNITTEST_CHECK(params_list);
    UNITTEST_CHECK_EQUAL(0, params_list->get_children()->size());

    auto def_block_stmt = std::static_pointer_cast<DefBlockStmt>(func_stmt->def_blocks());
    UNITTEST_CHECK(def_block_stmt);
    UNITTEST_CHECK_EQUAL(1, def_block_stmt->get_children()->size());
}