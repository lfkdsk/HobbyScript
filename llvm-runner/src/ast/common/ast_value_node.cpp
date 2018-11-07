//
// Created by 刘丰恺 on 2018/11/4.
//

#include <llvm/IR/Instructions.h>
#include "ast_value_node.h"

ast_value_node::ast_value_node(json &load_json) : ast_node(load_json) {}

llvm::Value *ast_value_node::get_llvm_value() const {
    return llvm_value;
}

const value_literal &ast_value_node::get_literal() const {
    return literal;
}

const llvm::Value *ast_value_node::get_llvm_mem() const {
    if (llvm_mem != nullptr) {
        return llvm_mem;
    } else if (auto *llvm_inst = llvm::dyn_cast<llvm::LoadInst>(llvm_value)) {
        // We give memory support if the value is in memory
        return llvm_inst->getPointerOperand();
    } else {
        return nullptr;
    }
}
