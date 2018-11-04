//
// Created by 刘丰恺 on 2018/8/3.
//

#ifndef LLVM_RUNNER_ASTLIST_H
#define LLVM_RUNNER_ASTLIST_H

#include "ast_node.h"

template<class T>
using vector = std::vector<T>;
using json_vector = vector<json>;
using ast_node_list = vector<pointer<ast_node>>;

class ast_list : public ast_node {
public:
    ast_list(const json &load_json, pointer<ast_node_list> children);

    pointer<ast_node_list> get_children();

private:
    pointer<ast_node_list> children;
};

#endif //LLVM_RUNNER_ASTLIST_H
