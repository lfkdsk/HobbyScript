//
// Created by 刘丰恺 on 2018/11/5.
//

#include "ast/common/ast_value_leaf.h"
#include "ast_bool_literal.h"

ast_bool_literal::ast_bool_literal(const json &load_json) : ast_literal(load_json) {
    this->literal.value.boo = token["value"].GetBool();
    this->literal.apply = true;
}

bool ast_bool_literal::get_bool() {
    return this->literal.value.boo;
}


