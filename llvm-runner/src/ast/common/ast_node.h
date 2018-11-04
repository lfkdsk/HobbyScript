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
using pointer = std::shared_ptr<T>;
using value = llvm::Value;
using value_pointer = value *;
using llvm_context = llvm::LLVMContext;

class ast_node {
public:
    ast_node(const json &load_json);

    virtual ~ast_node() {}

    const json &get_json();

    int get_tag() { return tag; };

private:
    json load_json;
    int tag;
};


#endif //LLVM_RUNNER_ASTNODE_H
