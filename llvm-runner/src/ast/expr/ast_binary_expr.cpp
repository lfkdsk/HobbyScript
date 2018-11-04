//
// Created by 刘丰恺 on 2018/8/3.
//

#include "ast_binary_expr.h"

ast_binary_expr::ast_binary_expr(const json &load_json, const pointer<ast_node_list> &children) : ast_list(load_json, children) {
    this->left_node = children->at(0);
    this->mid_op = children->at(1);
    this->right_node = children->at(2);
}

pointer<ast_node> ast_binary_expr::get_left_node() {
    return this->left_node;
}

pointer<ast_node> ast_binary_expr::get_right_node() {
    return this->right_node;
}

pointer<ast_node> ast_binary_expr::get_mid_op() {
    return this->mid_op;
}
