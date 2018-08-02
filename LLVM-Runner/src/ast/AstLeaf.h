//
// Created by 刘丰恺 on 2018/8/2.
//

#ifndef LLVM_RUNNER_ASTLEAF_H
#define LLVM_RUNNER_ASTLEAF_H

#include "AstNode.h"

using string = std::string;
using StringPointer = std::shared_ptr<string>;


class AstLeaf : public AstNode {
public:
    AstLeaf(const json &load_json);

    const json &get_token();

    string get_text();

private:
    json token;
};

using AstLeafPointer = std::shared_ptr<AstLeaf>;

#endif //LLVM_RUNNER_ASTLEAF_H
