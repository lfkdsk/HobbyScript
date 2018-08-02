//
// Created by 刘丰恺 on 2018/8/3.
//

#ifndef LLVM_RUNNER_BINARYEXPR_H
#define LLVM_RUNNER_BINARYEXPR_H

#include "AstList.h"

class BinaryExpr : public AstList {
public:
    BinaryExpr(const json &load_json, const AstNodeListPointer &children);

    AstNodePointer get_left_node();

    AstNodePointer get_right_node();

    AstNodePointer get_mid_op();

private:
    AstNodePointer left_node;
    AstNodePointer right_node;
    AstNodePointer mid_op;
};

using BinaryExprPointer = std::shared_ptr<BinaryExpr>;

#endif //LLVM_RUNNER_BINARYEXPR_H
