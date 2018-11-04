//
// Created by 刘丰恺 on 2018/11/4.
//

#ifndef LLVM_RUNNER_AST_VALUE_LEAF_H
#define LLVM_RUNNER_AST_VALUE_LEAF_H


#include "ast/common/ast_leaf.h"

struct value_literal {
    bool apply;
    string str_value;
    union {
        int num;
        double real;
        char chr;
        bool boo;
    } value;
};

class ast_value_leaf : public ast_leaf {
public:

    ast_value_leaf(const json &load_json);

    llvm::Value *get_llvm_value() const;

    const value_literal &get_literal() const;

protected:
    value_literal literal = {false};
    llvm::Value *llvm_value = nullptr;
};


#endif //LLVM_RUNNER_AST_VALUE_LEAF_H
