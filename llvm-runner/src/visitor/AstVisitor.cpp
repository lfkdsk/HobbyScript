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

pointer<AstNode> AstVisitor::visit_ast_node(const json &node) {
    return nullptr;
}

pointer<AstNode> AstVisitor::visit_ast_leaf(const json &node) {
    return pointer<AstLeaf>(new AstLeaf(node));
}

pointer<AstNode> AstVisitor::visit_binary_expr(const json &node) {
    std::vector<json> children = node["children"];
    return pointer<BinaryExpr>(new BinaryExpr(node, node_to_list(children)));
}

pointer<AstNode> AstVisitor::visit_ast_list(const json &node) {
    jsonVector children = node["children"];
    return pointer<AstList>(new AstList(node, node_to_list(children)));
}

pointer<AstNode> AstVisitor::visit_number(const json &node) {
    return pointer<NumberLiteral>(new NumberLiteral(node));
}


pointer<AstNode> AstVisitor::visit_string(const json &node) {
    return pointer<StringLiteral>(new StringLiteral(node));
}

pointer<AstNode> AstVisitor::visit_fun_stmt(const json &node) {
    jsonVector children = node["children"];
    return pointer<FuncStmt>(new FuncStmt(node, node_to_list(children)));
}


pointer<AstNode> AstVisitor::visit_def_block(const json &node) {
    jsonVector children = node["children"];
    return pointer<DefBlockStmt>(new DefBlockStmt(node, this->node_to_list(children)));
}

pointer<AstNode> AstVisitor::visit(const json &load_json) {
    int tag = load_json["tag"];
    pointer<AstNode> result;
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

pointer<AstNode> AstVisitor::visit() {
    return visit(this->load_json);
}

pointer<AstNodeList> AstVisitor::node_to_list(jsonVector &children) {
    pointer<AstNodeList> children_list(new AstNodeList());
    std::for_each(children.begin(), children.end(), [this, children_list](auto child_json) {
        pointer<AstNode> child = visit(child_json);
        children_list->push_back(child);
    });

    return children_list;
}
