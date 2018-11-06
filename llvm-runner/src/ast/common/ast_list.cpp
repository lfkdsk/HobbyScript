//
// Created by 刘丰恺 on 2018/8/3.
//

#include <visitor/AstVisitor.h>
#include "ast_list.h"

ast_list::ast_list(json &load_json)
        : ast_value_leaf(load_json) {
    pointer<ast_node_list> children_list(new ast_node_list());
    for (auto &child_json : this->load_json["children"].GetArray()) {
        pointer<ast_node> child = ast_visitor.visit(child_json);
        children_list->push_back(child);
    }

    this->children = children_list;
};

pointer<ast_node_list> ast_list::get_children() {
    return children;
}
