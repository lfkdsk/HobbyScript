//
// Created by 刘丰恺 on 2018/8/2.
//

#include "ast_leaf.h"
#include "rapidjson/pointer.h"

static json nothing("nothing");

ast_leaf::ast_leaf(json &load_json)
        : ast_node(load_json),
          token{
                  this->load_json.HasMember("token")
                  ? this->load_json["token"].Move()
                  : nothing
          } {};

const json &ast_leaf::get_token() {
    return this->token;
}

string ast_leaf::get_text() {
    string text = token["text"].GetString();
    return text;
}