//
// Created by 刘丰恺 on 2018/8/1.
//

#ifndef LLVM_RUNNER_ASTNODE_H
#define LLVM_RUNNER_ASTNODE_H

#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <json.hpp>

using json=nlohmann::json;
template<class T>
using Pointer = std::shared_ptr<T>;
using Value = llvm::Value;
using ValuePointer = Value *;
using LLVMContext = llvm::LLVMContext;

class AstNode {
public:
    AstNode(const json &load_json);

    virtual ~AstNode() {}

    const json &get_json();

    int get_tag() { return tag; };

private:
    json load_json;
    int tag;
};


#endif //LLVM_RUNNER_ASTNODE_H
