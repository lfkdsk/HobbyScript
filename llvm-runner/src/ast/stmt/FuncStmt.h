//
// Created by 刘丰恺 on 2018/8/8.
//

#ifndef LLVM_RUNNER_FUNCSTMT_H
#define LLVM_RUNNER_FUNCSTMT_H

#include "../common/ast_list.h"
#include "../common/ast_leaf.h"
#include "DefBlockStmt.h"

class FuncStmt : public ast_list {
public:
    FuncStmt(const json &load_json, pointer<ast_node_list> children);

public:
    pointer<ast_leaf> name() {
        return std::static_pointer_cast<ast_leaf>(this->get_children()->at(0));
    }

    pointer<ast_list> params_list() {
        return std::static_pointer_cast<ast_list>(this->get_children()->at(1));
    }

    pointer<DefBlockStmt> def_blocks() {
        return std::static_pointer_cast<DefBlockStmt>(this->get_children()->at(2));
    }
};


#endif //LLVM_RUNNER_FUNCSTMT_H
