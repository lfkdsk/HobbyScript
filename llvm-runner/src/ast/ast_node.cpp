//
// Created by 刘丰恺 on 16/1/2020.
//

#include "ast_node.h"

#include <utility>

extern int yylineno;

AstNode::AstNode(std::string n) : name(std::move(n)) {
    line_num = yylineno;
}