//
// Created by 刘丰恺 on 2018/8/1.
//

#include "AstVisitor.h"

AstVisitor::AstVisitor() {}

AstVisitor::~AstVisitor() {}

pointer<ast_node> AstVisitor::visit_ast_node(const rapidjson::Value &node) {
    return nullptr;
}

pointer<ast_node> AstVisitor::visit_ast_leaf(const rapidjson::Value &node) {
    return pointer<ast_leaf>(new ast_leaf(node));
}

pointer<ast_node> AstVisitor::visit_binary_expr(const rapidjson::Value &node) {
    return pointer<ast_binary_expr>(new ast_binary_expr(node));
}

pointer<ast_node> AstVisitor::visit_ast_list(const rapidjson::Value &node) {
    return pointer<ast_list>(new ast_list(node));
}

pointer<ast_node> AstVisitor::visit_number(const rapidjson::Value &node) {
    return pointer<ast_number_literal>(new ast_number_literal(node));
}


pointer<ast_node> AstVisitor::visit_string(const rapidjson::Value &node) {
    return pointer<ast_string_literal>(new ast_string_literal(node));
}

pointer<ast_node> AstVisitor::visit_fun_stmt(const rapidjson::Value &node) {
    return pointer<FuncStmt>(new FuncStmt(node));
}


pointer<ast_node> AstVisitor::visit_def_block(const rapidjson::Value &node) {
    return pointer<DefBlockStmt>(new DefBlockStmt(node));
}

pointer<ast_node> AstVisitor::visit(const rapidjson::Value &load_json) {
    int tag = load_json["tag"].GetInt();
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
    throw std::runtime_error("illegal method call.");
}