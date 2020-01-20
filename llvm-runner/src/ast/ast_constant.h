//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_AST_CONSTANT_H
#define LLVM_RUNNER_AST_CONSTANT_H

#include "ast_node.h"

class AstIntegerConstant : public AstNode, public AST_BASE(AstIntegerConstant) {
public:
    explicit AstIntegerConstant(QString name);
public:
    void set_value(int32_t v);

    void set_value(int64_t v);

private:
    int64_t _value = 0;
    int _bits = 0;
};

class AstFloatConstant : public AstNode, public AST_BASE(AstFloatConstant) {
public:
    AstFloatConstant(QString name, double value, bool is_double);

public:
    double value = 0;
    bool is_double = true;
};

class AstBoolConstant : public AstNode, public AST_BASE(AstBoolConstant) {
public:
    AstBoolConstant(QString name, bool value);

public:
    bool value = false;
};

#endif //LLVM_RUNNER_AST_CONSTANT_H
