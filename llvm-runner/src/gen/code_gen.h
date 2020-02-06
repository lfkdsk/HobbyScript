//
// Created by 刘丰恺 on 17/1/2020.
//

#ifndef LLVM_RUNNER_CODE_GEN_H
#define LLVM_RUNNER_CODE_GEN_H

#include "common/common.h"
#include "common/gen_common.h"
#include "visitor/llvm_gen_visitor.h"

class CodeGen : public GEN_BASE(CodeGen) {
public:
    explicit CodeGen(llvm::Type *t = nullptr) : type(t) {
        this->runtime_type = CodeGenTy;
    };

    explicit CodeGen(llvm::Value *v) : value(v), type(v == nullptr ? nullptr : v->getType()) {
        this->runtime_type = CodeGenTy;
    };

    virtual ~ CodeGen() {}

public:
    llvm::Type *type = nullptr;
    llvm::Value *value = nullptr;

    bool is_params = false;
    bool is_escape = false;

    GenType runtime_type;

public:
    inline void set_codegen_result(llvm::Value *result) {
        this->value = result;
    }

    inline llvm::Value *codegen_result() {
        return value;
    }
public:
    virtual llvm::Value *generate(LLVMCodeGenVisitor *visitor);

    llvm::Value *load(llvm::IRBuilder<> &builder, llvm::Value *v);
};


#endif //LLVM_RUNNER_CODE_GEN_H
