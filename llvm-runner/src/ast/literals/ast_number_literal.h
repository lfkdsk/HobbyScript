//
// Created by 刘丰恺 on 2018/8/2.
//

#ifndef LLVM_RUNNER_NUMBERLITERAL_H
#define LLVM_RUNNER_NUMBERLITERAL_H

#include "ast_literal.h"
#include <llvm/ADT/APFloat.h>
#include <llvm/IR/Constants.h>

class ast_number_literal : public ast_literal {
public:
    ast_number_literal(const json &load_json);

    double get_value();

    void generate_code() override;
};

#endif //LLVM_RUNNER_NUMBERLITERAL_H
