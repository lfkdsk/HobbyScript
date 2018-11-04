//
// Created by 刘丰恺 on 2018/8/2.
//

#include <iostream>
#include "NumberLiteral.h"

NumberLiteral::NumberLiteral(const json &load_json) : AstNode(load_json) {
    json token = load_json["token"];
    this->value = token["value"];
}

NumberLiteral::~NumberLiteral() {}

double NumberLiteral::getValue() {
    return this->value;
}

