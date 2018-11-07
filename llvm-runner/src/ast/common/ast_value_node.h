//
// Created by 刘丰恺 on 2018/11/4.
//

#ifndef LLVM_RUNNER_AST_VALUE_LEAF_H
#define LLVM_RUNNER_AST_VALUE_LEAF_H


#include <llvm/IR/Value.h>
#include "ast_node.h"

struct value_literal {
    bool apply;
    union {
        int num;
        double real;
        char chr;
        bool boo;
    } value;
};

class ast_value_node : public ast_node {
public:

    ast_value_node(json &load_json);

    llvm::Value *get_llvm_value() const;

    const value_literal &get_literal() const;

    const llvm::Value *get_llvm_mem() const;

protected:
    value_literal literal = {false};
    llvm::Value *llvm_value = nullptr;
    llvm::Value *llvm_mem = nullptr;
};

#endif //LLVM_RUNNER_AST_VALUE_LEAF_H
