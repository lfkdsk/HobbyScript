//
// Created by 刘丰恺 on 19/1/2020.
//

#ifndef LLVM_RUNNER_AST_VALUE_H
#define LLVM_RUNNER_AST_VALUE_H

#include "ast_node.h"

class AstValue : public AstNode, public AST_BASE(AstValue) {
public:
    AstNode* value = nullptr;
};


#endif //LLVM_RUNNER_AST_VALUE_H
