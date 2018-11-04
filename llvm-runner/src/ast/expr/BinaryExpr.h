//
// Created by 刘丰恺 on 2018/8/3.
//

#ifndef LLVM_RUNNER_BINARYEXPR_H
#define LLVM_RUNNER_BINARYEXPR_H

#include "../common/ast_list.h"

class BinaryExpr : public ast_list {
public:
    BinaryExpr(const json &load_json, const pointer<ast_node_list> &children);

    pointer<ast_node> get_left_node();

    pointer<ast_node> get_right_node();

    pointer<ast_node> get_mid_op();

private:
    pointer<ast_node> left_node;
    pointer<ast_node> right_node;
    pointer<ast_node> mid_op;
};

#endif //LLVM_RUNNER_BINARYEXPR_H
