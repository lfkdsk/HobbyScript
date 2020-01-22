//
// Created by 刘丰恺 on 23/1/2020.
//

#ifndef LLVM_RUNNER_AST_CLASS_H
#define LLVM_RUNNER_AST_CLASS_H

#include "ast_node.h"

class AstDefClass : public AstNode, AST_BASE(AstDefClass) {
public:
    CodeGen *make_new_class(
            AstContext *parent,
            QVector<QPair<QString, CodeGen *>> &args,
            QVector<AstType *> *template_types = nullptr
    );
};


#endif //LLVM_RUNNER_AST_CLASS_H
