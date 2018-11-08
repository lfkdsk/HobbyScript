//
// Created by 刘丰恺 on 2018/11/7.
//

#include <gtest/gtest.h>
#include "ast/ast_nodes.hpp"
//#include "gen/generator_context.h"
//#include "visitor/AstVisitor.h"

#define CHECK_NON_NULL(value) \
    do { \
        EXPECT_NE(nullptr, value); \
    } while(0);\


TEST (AST, TEST_CREATE_AST_NODE) {
    auto mock_ast_node = pointer<ast_node>(new ast_node(1));
    CHECK_NON_NULL(mock_ast_node);
    EXPECT_EQ(1, mock_ast_node->get_tag());
}