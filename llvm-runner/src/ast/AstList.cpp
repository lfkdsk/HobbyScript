#include <utility>

#include <utility>

#include <utility>

//
// Created by 刘丰恺 on 2018/8/3.
//

#include "AstList.h"

AstList::AstList(const json &load_json, Pointer<AstNodeList> children)
        : AstNode(load_json) {
    this->children = std::move(children);
};

Pointer<AstNodeList> AstList::get_children() {
    return children;
}


