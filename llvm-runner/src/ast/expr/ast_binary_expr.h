//
// Created by 刘丰恺 on 2018/8/3.
//

#ifndef LLVM_RUNNER_BINARYEXPR_H
#define LLVM_RUNNER_BINARYEXPR_H

#include "ast/common/ast_value_leaf.h"
#include "ast/common/ast_list.h"


class ast_binary_expr : public ast_list {
public:
    ast_binary_expr(json &load_json);

    pointer<ast_value_leaf> get_left_node();

    pointer<ast_value_leaf> get_right_node();

    pointer<ast_leaf> get_mid_op();

    void generate_code() override;

private:
    pointer<ast_value_leaf> left_node;
    pointer<ast_value_leaf> right_node;
    pointer<ast_leaf> mid_op;
};

#endif //LLVM_RUNNER_BINARYEXPR_H
