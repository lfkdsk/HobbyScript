//
// Created by 刘丰恺 on 16/1/2020.
//

#ifndef LLVM_RUNNER_AST_LET_H
#define LLVM_RUNNER_AST_LET_H


#include "ast_node.h"
#include "common/type_common.h"

class AstLet : public AstNode, public AST_BASE(AstLet) {
public:
    AstType *var_type = nullptr;
    AstNode *var_expr = nullptr;
    int flag = 0;
};


#endif //LLVM_RUNNER_AST_LET_H
