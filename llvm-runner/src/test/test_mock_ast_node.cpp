//
// Created by 刘丰恺 on 2018/11/7.
//

#include "unitcpp/UnitTest++.h"
#include "ast/common/ast_node.h"
#include "visitor/AstVisitor.h"

TEST (TEST_CREATE_AST_NODE) {
    auto mock_ast_node = pointer<ast_node>(new ast_node(AST_LEAF));
    REQUIRE CHECK (mock_ast_node);
    REQUIRE UNITTEST_CHECK_EQUAL(AST_LEAF, mock_ast_node->get_tag());
}