//
// Created by 刘丰恺 on 2018/8/8.
//

#ifndef LLVM_RUNNER_DEFBLOCKSTMT_H
#define LLVM_RUNNER_DEFBLOCKSTMT_H

#include "../common/ast_list.h"

class DefBlockStmt : public ast_list {
public:
    DefBlockStmt(const json &load_json);

    pointer<ast_node_list> expressions() {
        return this->get_children();
    }
};


#endif //LLVM_RUNNER_DEFBLOCKSTMT_H
