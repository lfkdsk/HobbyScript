//
// Created by 刘丰恺 on 2018/11/4.
//

#ifndef LLVM_RUNNER_AST_LITERAL_H
#define LLVM_RUNNER_AST_LITERAL_H


#include "ast/common/ast_value_node.h"
#include "ast/common/ast_leaf.h"

class ast_literal : public ast_leaf {

public:
    ast_literal(json &load_json);
};


#endif //LLVM_RUNNER_AST_LITERAL_H
