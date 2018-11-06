//
// Created by 刘丰恺 on 2018/11/5.
//

#ifndef LLVM_RUNNER_AST_BOOL_LITERAL_H
#define LLVM_RUNNER_AST_BOOL_LITERAL_H


#include "ast_literal.h"

class ast_bool_literal : ast_literal {

public:
    ast_bool_literal(json &load_json);

    bool get_bool();
};


#endif //LLVM_RUNNER_AST_BOOL_LITERAL_H
