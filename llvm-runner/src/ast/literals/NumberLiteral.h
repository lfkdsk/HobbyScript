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

class NumberLiteral : public ast_node {
public:
    NumberLiteral(const json &load_json);

    ~NumberLiteral() override;

    double getValue();
private:
    double value;
};

#endif //LLVM_RUNNER_NUMBERLITERAL_H
