//
// Created by 刘丰恺 on 2018/8/2.
//

#include <iostream>
#include "number_literal.h"

number_literal::number_literal(const json &load_json) : ast_node(load_json) {
    json token = load_json["token"];
    this->value = token["value"];
}

number_literal::~number_literal() {}

double number_literal::getValue() {
    return this->value;
}

