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

pointer<ast_node> AstVisitor::visit_ast_node(const json &node) {
    return nullptr;
}

pointer<ast_node> AstVisitor::visit_ast_leaf(const json &node) {
    return pointer<ast_leaf>(new ast_leaf(node));
}

pointer<ast_node> AstVisitor::visit_binary_expr(const json &node) {
    std::vector<json> children = node["children"];
    return pointer<ast_binary_expr>(new ast_binary_expr(node, node_to_list(children)));
}

pointer<ast_node> AstVisitor::visit_ast_list(const json &node) {
    json_vector children = node["children"];
    return pointer<ast_list>(new ast_list(node, node_to_list(children)));
}

pointer<ast_node> AstVisitor::visit_number(const json &node) {
    return pointer<number_literal>(new number_literal(node));
}


pointer<ast_node> AstVisitor::visit_string(const json &node) {
    return pointer<string_literal>(new string_literal(node));
}

pointer<ast_node> AstVisitor::visit_fun_stmt(const json &node) {
    json_vector children = node["children"];
    return pointer<FuncStmt>(new FuncStmt(node, node_to_list(children)));
}


pointer<ast_node> AstVisitor::visit_def_block(const json &node) {
    json_vector children = node["children"];
    return pointer<DefBlockStmt>(new DefBlockStmt(node, this->node_to_list(children)));
}

pointer<ast_node> AstVisitor::visit(const json &load_json) {
    int tag = load_json["tag"];
    pointer<ast_node> result;
    switch (tag) {
        case BINARY_EXPR: {
            result = visit_binary_expr(load_json);
            break;
        }

        case NUMBER_LITERAL: {
            result = visit_number(load_json);
            break;
        }

        case STRING_LITERAL: {
            result = visit_string(load_json);
            break;
        }

        case AST_LEAF: {
            result = visit_ast_leaf(load_json);
            break;
        }

        case PARAMS_LIST:
        case AST_LIST: {
            result = visit_ast_list(load_json);
            break;
        }

        case DEF_BLOCK: {
            result = visit_def_block(load_json);
            break;
        }

        case FUNCTION:
            result = visit_fun_stmt(load_json);
            break;

        default: {
            break;
        }
    }

//    std::cout << result->get_json().dump(4) << std::endl;
    return result;
}

pointer<ast_node> AstVisitor::visit() {
    return visit(this->load_json);
}

pointer<ast_node_list> AstVisitor::node_to_list(json_vector &children) {
    pointer<ast_node_list> children_list(new ast_node_list());
    std::for_each(children.begin(), children.end(), [this, children_list](auto child_json) {
        pointer<ast_node> child = visit(child_json);
        children_list->push_back(child);
    });

    return children_list;
}
