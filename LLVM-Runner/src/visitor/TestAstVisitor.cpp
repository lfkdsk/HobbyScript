//
// Created by 刘丰恺 on 2018/8/2.
//

#include "unitcpp/UnitTest++.h"
#include "AstVisitor.h"
#include "json.hpp"

using json = nlohmann::json;

TEST (TestPrintNumeric1) {
    json testJson = json::parse(
            R"({"token":{"value":1,"lineNumber":1,"tag":270},"tag":270,"type":"NumberLiteral"})");
    AstVisitor visitor(testJson);
    AstNodePointer node_pointer = visitor.visit();
    NumberLiteralPointer literal = std::static_pointer_cast<NumberLiteral>(node_pointer);
    UNITTEST_CHECK_EQUAL(1, literal->getValue());
}


TEST(TestPrintAstLeaf) {
    json testJson = json::parse(
            R"({"token":{"text":"+","lineNumber":1,"tag":264})");
    AstVisitor visitor(testJson);
    AstNodePointer node_pointer = visitor.visit();
    NumberLiteralPointer literal = std::static_pointer_cast<NumberLiteral>(node_pointer);
}