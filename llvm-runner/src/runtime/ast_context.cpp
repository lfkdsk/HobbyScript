//
// Created by 刘丰恺 on 17/1/2020.
//

#include "ast_context.h"

AstContext::AstContext(llvm::Module *m) : module(m), parent(nullptr) {}

AstContext::AstContext(AstContext *p) {
    if (!p) {
        return;
    }

    this->module = p->module;
    this->path_name = p->path_name;
}

llvm::LLVMContext & AstContext::context() {
    return module ? module->getContext() : parent->context();
}