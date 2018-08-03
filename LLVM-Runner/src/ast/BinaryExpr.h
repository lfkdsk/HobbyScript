//
// Created by 刘丰恺 on 2018/8/3.
//

#ifndef LLVM_RUNNER_BINARYEXPR_H
#define LLVM_RUNNER_BINARYEXPR_H

#include "AstList.h"

class BinaryExpr : public AstList {
public:
    BinaryExpr(const json &load_json, const Pointer<AstNodeList> &children);

    Pointer<AstNode> get_left_node();

    Pointer<AstNode> get_right_node();

    Pointer<AstNode> get_mid_op();

private:
    Pointer<AstNode> left_node;
    Pointer<AstNode> right_node;
    Pointer<AstNode> mid_op;
};

#endif //LLVM_RUNNER_BINARYEXPR_H
