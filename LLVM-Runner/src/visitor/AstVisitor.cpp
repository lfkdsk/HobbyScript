#include <utility>

//
// Created by 刘丰恺 on 2018/8/1.
//

#include "AstVisitor.h"
#include <UnitTest++/UnitTest++.h>

AstVisitor::AstVisitor(const json& load) {
    this->load_json = load;
}

AstVisitor::~AstVisitor() {
    this->load_json.clear();
}

const json& AstVisitor::get_json() {
    return load_json;
}

AstNode AstVisitor::visit_ast_node(const json& json_object) {

}

AstNode AstVisitor::visit_ast_leaf(const json& json_object) {

}

AstNode AstVisitor::visit_ast_list(const json& json_object) {

}

AstNode AstVisitor::visit_number(const json &json_object) {

}
