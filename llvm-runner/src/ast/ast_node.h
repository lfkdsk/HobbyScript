//
// Created by 刘丰恺 on 16/1/2020.
//

#ifndef LLVM_RUNNER_AST_NODE_H
#define LLVM_RUNNER_AST_NODE_H

#include <string>

class AstNode {
public:
    AstNode(const std::string &n = std::string());
    virtual ~AstNode() {}
public:
    std::string name;

};

class AstType {

};

#endif //LLVM_RUNNER_AST_NODE_H
