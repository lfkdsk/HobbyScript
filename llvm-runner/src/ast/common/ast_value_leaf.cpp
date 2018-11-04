//
// Created by 刘丰恺 on 2018/11/4.
//

#include "ast_value_leaf.h"


llvm::Value *ast_value_leaf::get_llvm_value() const {
    return llvm_value;
}

const value_literal &ast_value_leaf::get_literal() const {
    return literal;
}

ast_value_leaf::ast_value_leaf(const json &load_json) : ast_leaf(load_json) {}

