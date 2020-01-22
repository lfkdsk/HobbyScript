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

llvm::LLVMContext &AstContext::context() {
    return module ? module->getContext() : parent->context();
}

CodeGen *AstContext::find_symbol_value(const QString &var_name, bool recursive) {
    auto *p = get_map_value(symbols, var_name);
    if (p) {
        return p;
    }

    if (recursive && parent) {
        return parent->find_symbol_value(var_name, recursive);
    }

    auto *value = module->getGlobalVariable(var_name.toUtf8().toStdString());
    if (!value) {
        return nullptr;
    }

    return nullptr;
}

void AstContext::set_symbol_value(const QString &var_name, CodeGen *value) {
    auto iter = symbols.find(var_name);
    if (iter != symbols.end()) {
        auto *type = iter.value()->type;
        if (!type) {
            throw create_runtime_error("duplicate variable: " + var_name);
        }
        delete iter.value();
    }
    // save value in symbols
    symbols[var_name] = value;
}
