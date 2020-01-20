//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_AST_PACKAGE_H
#define LLVM_RUNNER_AST_PACKAGE_H

#include "ast_node.h"
#include "utils/visitor_common.h"

class AstPackage : public AstNode, public AST_BASE(AstPackage) {
public:
    QVector<QString> names;
    QVector<AstNode *> lines;
public:
    AstContext *compile(llvm::Module *m);

private:
    QVector<CodeGen *> codegens;
    CodeGenVisitor *code_gen_visitor = nullptr;
};


#endif //LLVM_RUNNER_AST_PACKAGE_H
