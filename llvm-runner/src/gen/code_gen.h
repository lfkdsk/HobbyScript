//
// Created by 刘丰恺 on 17/1/2020.
//

#ifndef LLVM_RUNNER_CODE_GEN_H
#define LLVM_RUNNER_CODE_GEN_H

#include "common/common.h"
#include "common/gen_common.h"
#include "visitor/llvm_gen_visitor.h"

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

class CodeGen : public GEN_BASE(CodeGen) {
public:
    explicit CodeGen(llvm::Type *t = nullptr) : type(t) {};

    explicit CodeGen(llvm::Value *v) : value(v), type(v == nullptr ? nullptr : v->getType()) {};

    virtual ~ CodeGen() {}

public:
    llvm::Type *type = nullptr;
    llvm::Value *value = nullptr;

    bool isParams = false;
    bool isEscape = false;
public:
    virtual llvm::Value *generate(LLVMCodeGenVisitor &visitor);

    llvm::Value *load(llvm::IRBuilder<> &builder, llvm::Value *v);
};


#endif //LLVM_RUNNER_CODE_GEN_H
