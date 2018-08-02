//
// Created by 刘丰恺 on 2018/8/1.
//

#include "AstVisitor.h"

AstVisitor::AstVisitor(const json &load) {
    this->load_json = load;
}

AstVisitor::~AstVisitor() {
    this->load_json.clear();
}

const json &AstVisitor::get_json() {
    return load_json;
}

AstNodePointer AstVisitor::visit_ast_node(const json &json_object) {

}

AstNodePointer AstVisitor::visit_ast_leaf(const json &json_object) {

}

AstNodePointer AstVisitor::visit_ast_list(const json &json_object) {
    return AstNodePointer();
}

AstNodePointer AstVisitor::visit_number(const json &json_object) {
    return AstNodePointer(new NumberLiteral(json_object));
}

AstNodePointer AstVisitor::visit_binary_expr(const json &json_object) {
    std::vector<json> children = json_object["children"];
    auto left = visit(children[0]);
    auto right = visit(children[2]);
    auto op = visit(children[1]);
}

AstNodePointer AstVisitor::visit(const json &load_json) {
    int tag = load_json["tag"];
    AstNodePointer result;
    switch (tag) {
        case BINARY_EXPR: {
            result = visit_binary_expr(load_json);
            break;
        }

        case NUMBER_LITERAL: {
            result = visit_number(load_json);
            break;
        }

        case AST_LEAF: {
            result = visit_number(load_json);
            break;
        }

        default: {
            break;
        }
    }

    std::cout << result->get_json().dump(4) << std::endl;
    return result;
}

AstNodePointer AstVisitor::visit() {
    return visit(this->load_json);
}

