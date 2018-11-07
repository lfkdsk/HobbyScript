//
// Created by 刘丰恺 on 2018/8/1.
//

#include "ast_node.h"

ast_node::ast_node(json &load_json) : load_json(load_json.Move()) {
    this->tag = load_json["tag"].GetInt();
}

ast_node::ast_node(int tag) : load_json(nothing) {
    this->tag = tag;
}

const rapidjson::Value &ast_node::get_json() {
    return load_json;
}

void ast_node::set_location(int lineno, int colno) {
    this->lineno = lineno;
    this->colno = colno;
}

void ast_node::generate_code() {

}
