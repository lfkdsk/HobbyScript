#include <utility>

#include <utility>

#include <utility>

#include <utility>

//
// Created by 刘丰恺 on 2018/8/3.
//

#include "ast_list.h"

ast_list::ast_list(const json &load_json, pointer<ast_node_list> children)
        : ast_value_leaf(load_json) {
    this->children = std::move(children);
};

pointer<ast_node_list> ast_list::get_children() {
    return children;
}


