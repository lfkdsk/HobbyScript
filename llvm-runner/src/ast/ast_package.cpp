//
// Created by 刘丰恺 on 20/1/2020.
//

#include "ast_package.h"
#include "visitor/visitors.hpp"

AstContext *AstPackage::compile(llvm::Module *module) {
    // TODO: import names.
    auto *block = new AstContext(module);
    block->module = module;
    block->path_name = name;
    // TODO: solve imports.
    this->code_gen_visitor = new CodeGenVisitor(block);
    for (auto line: lines) {
        this->code_gen_visitor->visit(*line);
        auto *v = line->codegen_result();
        if (v) {
            this->codegens.push_back(v);
        }
    }
    return block;
}

void AstPackage::codegen(llvm::Module *module) {

}
