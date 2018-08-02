//
// Created by 刘丰恺 on 2018/8/2.
//

#ifndef LLVM_RUNNER_NUMBERLITERAL_H
#define LLVM_RUNNER_NUMBERLITERAL_H

#include "AstNode.h"

class NumberLiteral : public AstNode {
public:
    NumberLiteral(const json &load_json);

    ~NumberLiteral() override;

    double getValue();

private:
    double value;
};

using NumberLiteralPointer = std::shared_ptr<NumberLiteral>;

#endif //LLVM_RUNNER_NUMBERLITERAL_H
