//
// Created by 刘丰恺 on 2018/8/2.
//

#include "AstLeaf.h"

AstLeaf::AstLeaf(const json &load_json) : AstNode(load_json) {
    this->token = load_json["token"];
}

const json &AstLeaf::get_token() {
    return this->token;
}

string AstLeaf::get_text() {
    string text = token["text"];
    return text;
}
