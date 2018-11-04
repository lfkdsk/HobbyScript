//
// Created by 刘丰恺 on 2018/8/2.
//

#ifndef LLVM_RUNNER_NUMBERLITERAL_H
#define LLVM_RUNNER_NUMBERLITERAL_H

#include "../common/ast_node.h"
#include <llvm/ADT/APFloat.h>
#include <llvm/IR/Constants.h>

using APFloat = llvm::APFloat;
using ConstantFP = llvm::ConstantFP;

class number_literal : public ast_node {
public:
    number_literal(const json &load_json);

    ~number_literal() override;

    double getValue();
private:
    double value;
};

#endif //LLVM_RUNNER_NUMBERLITERAL_H
