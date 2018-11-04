//
// Created by 刘丰恺 on 2018/8/3.
//

#ifndef LLVM_RUNNER_ASTLIST_H
#define LLVM_RUNNER_ASTLIST_H

#include "AstNode.h"

template<class T>
using Vector = std::vector<T>;
using jsonVector = Vector<json>;
using AstNodeList = Vector<pointer<AstNode>>;

class AstList : public AstNode {
public:
    AstList(const json &load_json, pointer<AstNodeList> children);

    pointer<AstNodeList> get_children();

private:
    pointer<AstNodeList> children;
};

#endif //LLVM_RUNNER_ASTLIST_H
