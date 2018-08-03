//
// Created by 刘丰恺 on 2018/8/3.
//

#ifndef LLVM_RUNNER_ASTLIST_H
#define LLVM_RUNNER_ASTLIST_H

#include "AstNode.h"

template<class T>
using Vector = std::vector<T>;
using jsonVector = Vector<json>;
using AstNodeList = Vector<Pointer<AstNode>>;

class AstList : public AstNode {
public:
    AstList(const json &load_json, Pointer<AstNodeList> children);

    Pointer<AstNodeList> get_children();

private:
    Pointer<AstNodeList> children;
};

#endif //LLVM_RUNNER_ASTLIST_H
