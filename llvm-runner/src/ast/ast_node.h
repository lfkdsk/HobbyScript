//
// Created by 刘丰恺 on 16/1/2020.
//

#ifndef LLVM_RUNNER_AST_NODE_H
#define LLVM_RUNNER_AST_NODE_H

#include <string>
#include "ast_context.h"
#include "gen/code_gen.h"

class AstNode {
public:
    AstNode(std::string n = std::string());

    virtual ~AstNode() {}
public:
    std::string name;
    int line_num;
};

class AstType {

};

#endif //LLVM_RUNNER_AST_NODE_H
