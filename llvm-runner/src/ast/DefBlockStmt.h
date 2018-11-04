//
// Created by 刘丰恺 on 2018/8/8.
//

#ifndef LLVM_RUNNER_DEFBLOCKSTMT_H
#define LLVM_RUNNER_DEFBLOCKSTMT_H

#include "AstList.h"

class DefBlockStmt : public AstList {
public:
    DefBlockStmt(const json &load_json, pointer<AstNodeList> children);

    pointer<AstNodeList> expressions() {
        return this->get_children();
    }
};


#endif //LLVM_RUNNER_DEFBLOCKSTMT_H
