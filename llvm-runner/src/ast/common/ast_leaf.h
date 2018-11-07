//
// Created by 刘丰恺 on 2018/8/2.
//

#ifndef LLVM_RUNNER_ASTLEAF_H
#define LLVM_RUNNER_ASTLEAF_H

#include "ast_node.h"
#include "ast_value_node.h"

class ast_leaf : public ast_value_node {
public:
    ast_leaf(json &load_json);

    const json &get_token();

    string &get_text();

protected:
    json &token;
    string text;
    bool is_token_value;
};

#endif //LLVM_RUNNER_ASTLEAF_H
