//
// Created by 刘丰恺 on 2018/8/1.
//

#include "AstNode.h"

AstNode::AstNode(const json &load_json) {
    this->load_json = load_json;
}

const json &AstNode::get_json() {
    return load_json;
}

Pointer<Value> AstNode::code_gen(LLVMContext context) {
    return Pointer<llvm::Value>();
}
