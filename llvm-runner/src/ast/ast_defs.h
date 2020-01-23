//
// Created by 刘丰恺 on 23/1/2020.
//

#ifndef LLVM_RUNNER_AST_DEFS_H
#define LLVM_RUNNER_AST_DEFS_H

#include "ast_node.h"
#include "common/common.h"
#include "common/type_common.h"
#include "ast/ast_class.h"

class AstDef : public AstNode, public AST_BASE(AstDef) {
public:
    AstDef();

    AstType *type;
    QVector<QPair<QString, AstNode *>> vars;
public:
    CodeGen *make_def_gen(
            AstContext *parent,
            AstType *ast_type,
            const QString &n,
            AstNode *var
    );
};


#endif //LLVM_RUNNER_AST_DEFS_H
