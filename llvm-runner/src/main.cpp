#include <iostream>
#include <fstream>
#include <gen/literals/generator_literals.h>
#include "spdlog/spdlog.h"
#include "json.hpp"
#include "unitcpp/UnitTest++.h"
#include "visitor/AstVisitor.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "gen/generator_context.h"
#include "llvm/IR/LegacyPassManager.h"


using json = nlohmann::json;

static pointer<ast_node> toAst(const json &inputJson) {
    AstVisitor visitor(inputJson);
    return visitor.visit();
}

int main(int, const char *[]) {
//    std::ifstream input("../result.ast");
//    for (std::string line; getline(input, line);) {
//        json inputJson = json::parse(line);
//        std::cout << inputJson.dump(4) << std::endl;
//        AstVisitor visitor(inputJson);
//    }
    json input = json::parse(R"({"afterPoint":0,"children":[{"token":{"value":1,"lineNumber":1,"tag":270},"tag":270,"type":"ast_number_literal"},{"token":{"text":"+","lineNumber":1,"tag":264},"tag":264,"type":"ast_leaf"},{"token":{"value":1111,"lineNumber":1,"tag":270},"tag":270,"type":"ast_number_literal"}],"tag":279,"type":"BinaryExpr"}
)");
    auto root = toAst(input);
    auto binary_expr_pointer = std::static_pointer_cast<ast_binary_expr>(root);

    llvm::FunctionType *func_type = llvm::FunctionType::get(gen::get_llvm_int_type(), false);
    llvm::Function *main_func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "main", &llvm_module);
    llvm::BasicBlock *entry = llvm::BasicBlock::Create(llvm_context, "entry", main_func);
    ir_builder.SetInsertPoint(entry);

    binary_expr_pointer->generate_code();
    ir_builder.CreateRet(binary_expr_pointer->get_llvm_value());

    llvm_module.print(llvm::outs(), nullptr);

    llvm::legacy::PassManager passMan;
    passMan.run(llvm_module);

    return 0;
}
