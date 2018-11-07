//
// Created by 刘丰恺 on 2018/8/2.
//

#include "ast_leaf.h"
#include "rapidjson/pointer.h"

ast_leaf::ast_leaf(json &load_json)
        : ast_value_node(load_json),
          token{
                  this->load_json.HasMember("token")
                  ? this->load_json["token"].Move()
                  : nothing
          } {
    this->is_token_value = this->load_json.HasMember("token");
    if (is_token_value && token.HasMember("text")) {
        this->text = this->token["text"].GetString();
    }
};

const json &ast_leaf::get_token() {
    return this->token;
}

string &ast_leaf::get_text() {
    return this->text;
}