//
// Created by 刘丰恺 on 2018/8/3.
//

#include "gen/generator_context.h"
#include "unitcpp/UnitTest++.h"
#include "json.hpp"
#include "visitor/AstVisitor.h"
#include "LLVMCodeGenVisitor.h"

using json = nlohmann::json;

SUITE (TestCodeGen) {
    static pointer<ast_node> toAst(const json &inputJson) {
        return ast_visitor.visit(inputJson);
    }

    TEST (NumberGenTest1) {
        json input = json::parse(
                R"({"token":{"value":1,"lineNumber":1,"tag":270},"tag":270,"type":"ast_number_literal"})");
        auto root = toAst(input);
        auto number = std::static_pointer_cast<ast_number_literal>(root);
        LLVMCodeGenVisitor visitor(root);
        auto result = visitor.visit_number(root);
        auto result_float = (ConstantFP *) result;
        UNITTEST_CHECK(result);
        UNITTEST_CHECK(result_float);
        UNITTEST_CHECK_EQUAL(1, result_float->getValueAPF().convertToDouble());
    }

//    TEST (BinaryGenTest1) {
//        json input = json::parse(R"({"afterPoint":0,"children":[{"token":{"value":1,"lineNumber":1,"tag":270},"tag":270,"type":"ast_number_literal"},{"token":{"text":"+","lineNumber":1,"tag":264},"tag":264,"type":"ast_leaf"},{"token":{"value":1111,"lineNumber":1,"tag":270},"tag":270,"type":"ast_number_literal"}],"tag":279,"type":"BinaryExpr"}
//)");
//        auto root = toAst(input);
//        auto binary_expr_pointer = std::static_pointer_cast<ast_binary_expr>(root);
//        binary_expr_pointer->generate_code();
//        llvm_module.dump();
//    }
}


