//
// Created by 刘丰恺 on 2018/8/3.
//

#include "gen/expr/generator_expr.h"
#include "ast_binary_expr.h"

ast_binary_expr::ast_binary_expr(const rapidjson::Value &load_json)
        : ast_list(load_json) {
    this->left_node = std::dynamic_pointer_cast<ast_value_leaf>(this->get_children()->at(0));
    this->mid_op = std::dynamic_pointer_cast<ast_leaf>(this->get_children()->at(1));
    this->right_node = std::dynamic_pointer_cast<ast_value_leaf>(this->get_children()->at(2));
}

pointer<ast_value_leaf> ast_binary_expr::get_left_node() {
    return this->left_node;
}

pointer<ast_value_leaf> ast_binary_expr::get_right_node() {
    return this->right_node;
}

pointer<ast_leaf> ast_binary_expr::get_mid_op() {
    return this->mid_op;
}

void ast_binary_expr::generate_code() {
    get_left_node()->generate_code();
    get_right_node()->generate_code();

    llvm_value = gen::gen_arith_add(
            get_left_node()->get_llvm_value(),
            get_right_node()->get_llvm_value()
    );
}
