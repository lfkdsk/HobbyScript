//
// Created by 刘丰恺 on 20/1/2020.
//

#include "ast_constant.h"

#include <utility>

/**
 * Ast Integer Constant.
 */
AstIntegerConstant::AstIntegerConstant(QString name) : AstNode(std::move(name)) {
    this->runtime_type = AstIntegerConstantTy;
}

void AstIntegerConstant::set_value(int32_t v) {
    this->_bits = 32;
    this->_value = v;
}

void AstIntegerConstant::set_value(int64_t v) {
    this->_bits = 64;
    this->_value = v;
}

/**
 * Ast Float Constant.
 */
AstFloatConstant::AstFloatConstant(QString name, double v, bool is_double) :
        AstNode(std::move(name)), value(v), is_double(is_double) {
}

/**
 * Ast Bool Constant.
 */
AstBoolConstant::AstBoolConstant(QString name, bool v) :
        AstNode(std::move(name)), value(v) {
}



