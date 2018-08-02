//
// Created by 刘丰恺 on 2018/8/3.
//

#ifndef LLVM_RUNNER_ASTLIST_H
#define LLVM_RUNNER_ASTLIST_H

#include "AstNode.h"

using jsonVector = std::vector<json>;
using AstNodeList = std::vector<AstNodePointer>;
using AstNodeListPointer = std::shared_ptr<AstNodeList>;

class AstList : public AstNode {
public:
    AstList(const json &load_json, AstNodeListPointer children);

    AstNodeListPointer get_children();

private:
    AstNodeListPointer children;
};

using AstListPointer = std::shared_ptr<AstList>;

#endif //LLVM_RUNNER_ASTLIST_H
