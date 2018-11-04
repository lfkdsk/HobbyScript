//
// Created by 刘丰恺 on 2018/8/2.
//

#include <iostream>
#include <ast/common/ast_value_leaf.h>
#include <gen/literals/generator_literals.h>
#include "ast_number_literal.h"

ast_number_literal::ast_number_literal(const json &load_json) : ast_literal(load_json) {
    json token = load_json["token"];
    this->literal.value.real = (double) token["value"];
    this->literal.apply = true;
}

double ast_number_literal::get_value() {
    return this->literal.value.real;
}

void ast_number_literal::generate_code() {
    llvm_value = gen::get_llvm_real(get_value());
}
