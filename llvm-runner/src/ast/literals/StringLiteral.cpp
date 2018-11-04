//
// Created by 刘丰恺 on 2018/8/8.
//

#include "StringLiteral.h"

StringLiteral::StringLiteral(const json &load_json) : ast_node(load_json) {
    json token = load_json["token"];
    this->text = token["literal"];
}
