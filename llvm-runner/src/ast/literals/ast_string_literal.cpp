//
// Created by 刘丰恺 on 2018/8/8.
//

#include "ast_string_literal.h"

ast_string_literal::ast_string_literal(const json &load_json) : ast_literal(load_json) {
    json token = load_json["token"];
    this->literal.str_value = token["literal"];
    this->literal.apply = true;
}
