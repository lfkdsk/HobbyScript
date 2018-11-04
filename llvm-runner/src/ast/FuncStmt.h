//
// Created by 刘丰恺 on 2018/8/8.
//

#ifndef LLVM_RUNNER_FUNCSTMT_H
#define LLVM_RUNNER_FUNCSTMT_H

#include "AstList.h"
#include "AstLeaf.h"
#include "DefBlockStmt.h"

class FuncStmt : public AstList {
public:
    FuncStmt(const json &load_json, Pointer<AstNodeList> children);

public:
    Pointer<AstLeaf> name() {
        return std::static_pointer_cast<AstLeaf>(this->get_children()->at(0));
    }

    Pointer<AstList> params_list() {
        return std::static_pointer_cast<AstList>(this->get_children()->at(1));
    }

    Pointer<DefBlockStmt> def_blocks() {
        return std::static_pointer_cast<DefBlockStmt>(this->get_children()->at(2));
    }
};


#endif //LLVM_RUNNER_FUNCSTMT_H
