//
// Created by 刘丰恺 on 2018/8/2.
//

#ifndef LLVM_RUNNER_ASTLEAF_H
#define LLVM_RUNNER_ASTLEAF_H

#include "AstNode.h"

class AstLeaf : public AstNode {
`public:
    AstLeaf(const json &load_json);
};


#endif //LLVM_RUNNER_ASTLEAF_H
