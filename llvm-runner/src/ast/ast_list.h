//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_AST_LIST_H
#define LLVM_RUNNER_AST_LIST_H

#include "ast/ast_node.h"

class AstList : public AstNode, AST_BASE(AstList) {
public:
    QVector<AstNode*> lines;
};


#endif //LLVM_RUNNER_AST_LIST_H
