//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_AST_LITERAL_H
#define LLVM_RUNNER_AST_LITERAL_H

#include "ast_node.h"

class AstStringLiteral : public AstNode, public AST_BASE(AstStringLiteral) {
public:
    explicit AstStringLiteral(const QString &value);

    explicit AstStringLiteral(const char *v) : AstStringLiteral(QString(v)) {}
};


#endif //LLVM_RUNNER_AST_LITERAL_H
