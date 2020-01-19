//
// Created by 刘丰恺 on 16/1/2020.
//

#ifndef LLVM_RUNNER_AST_NODE_H
#define LLVM_RUNNER_AST_NODE_H

#include <string>
#include <utility>
#include "ast_context.h"
#include "gen/code_gen.h"
#include "utils/common.h"

class AstType;

class AstContext;

class CodeGen;

extern int yylineno;

class AstNode {
public:
    AstNode(QString n = QString()) : name(std::move(n)) {
        this->line_num = yylineno;
    };

    virtual ~AstNode() {}

public:
    QString name;
    int line_num;
};

#endif //LLVM_RUNNER_AST_NODE_H
