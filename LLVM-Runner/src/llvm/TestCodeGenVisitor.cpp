//
// Created by 刘丰恺 on 2018/8/3.
//

#include "UnitTest++/UnitTest++.h"
#include "json.hpp"

using json = nlohmann::json;

#include "../visitor/AstVisitor.h"
#include "LLVMCodeGenVisitor.h"

SUITE (TestCodeGen) {
    static Pointer<AstNode> toAst(const json &inputJson) {
        AstVisitor visitor(inputJson);
        return visitor.visit();
    }

    TEST (NumberGenTest1) {
        json input = json::parse(R"({"token":{"value":1,"lineNumber":1,"tag":270},"tag":270,"type":"NumberLiteral"})");
        auto root = toAst(input);
        auto number = std::static_pointer_cast<NumberLiteral>(root);
        LLVMCodeGenVisitor visitor(root);
        auto result = visitor.visit_number(root);
        auto result_float = (ConstantFP *) result;
        UNITTEST_CHECK(result);
        UNITTEST_CHECK(result_float);
        UNITTEST_CHECK_EQUAL(1, result_float->getValueAPF().convertToDouble());
    }
}


