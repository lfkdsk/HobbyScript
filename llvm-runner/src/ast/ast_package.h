//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_AST_PACKAGE_H
#define LLVM_RUNNER_AST_PACKAGE_H

#include "ast_node.h"

class AstPackage : public AstNode, public AST_BASE(AstPackage) {
public:
    std::vector<QString> names;
    std::vector<AstNode*> lines;
private:
    std::vector<CodeGen *> codegens;
};


#endif //LLVM_RUNNER_AST_PACKAGE_H
