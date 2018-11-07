//
// Created by 刘丰恺 on 2018/8/8.
//

#include <ast/common/ast_value_node.h>
#include "ast_string_literal.h"

ast_string_literal::ast_string_literal(json &load_json) : ast_literal(load_json) {
    this->str = token["literal"].GetString();
    this->literal = {true};
}
