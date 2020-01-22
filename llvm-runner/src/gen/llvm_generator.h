//
// Created by 刘丰恺 on 22/1/2020.
//

#ifndef LLVM_RUNNER_LLVM_GENERATOR_H
#define LLVM_RUNNER_LLVM_GENERATOR_H

#include "common/common.h"

struct LLVMGenerator {
    llvm::Module *module;
    llvm::Function *func;
    llvm::IRBuilder<> *ir_builder;
    llvm::BasicBlock *deallocate;
public:
    [[nodiscard]] llvm::LLVMContext &context() const { return ir_builder->getContext(); }

    [[nodiscard]] llvm::IRBuilder<> &builder() const { return *ir_builder; }

    // alloc var memory in function first block
    inline llvm::Value *alloc(llvm::Type *ty, const QString &name = "", llvm::Value *sz = nullptr) const {
        auto &block = func->getEntryBlock();
        llvm::IRBuilder<> b(&block);
        return b.CreateAlloca(ty, sz, name.toUtf8().toStdString());
    }
};

#endif //LLVM_RUNNER_LLVM_GENERATOR_H
