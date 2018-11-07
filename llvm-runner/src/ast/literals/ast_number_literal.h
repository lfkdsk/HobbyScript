//
// Created by 刘丰恺 on 2018/8/2.
//

#ifndef LLVM_RUNNER_NUMBERLITERAL_H
#define LLVM_RUNNER_NUMBERLITERAL_H

#include <iostream>
#include "ast_literal.h"
#include "ast/common/ast_value_node.h"
#include "gen/literals/generator_literals.h"

class ast_number_literal : public ast_literal {
public:
    ast_number_literal(json &load_json);

    double get_value();

    void generate_code() override;
};

#endif //LLVM_RUNNER_NUMBERLITERAL_H
