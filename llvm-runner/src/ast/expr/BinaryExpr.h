//
// Created by 刘丰恺 on 2018/8/3.
//

#ifndef LLVM_RUNNER_BINARYEXPR_H
#define LLVM_RUNNER_BINARYEXPR_H

#include "../common/AstList.h"

class BinaryExpr : public AstList {
public:
    BinaryExpr(const json &load_json, const pointer<AstNodeList> &children);

    pointer<AstNode> get_left_node();

    pointer<AstNode> get_right_node();

    pointer<AstNode> get_mid_op();

private:
    pointer<AstNode> left_node;
    pointer<AstNode> right_node;
    pointer<AstNode> mid_op;
};

#endif //LLVM_RUNNER_BINARYEXPR_H
