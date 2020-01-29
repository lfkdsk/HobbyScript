//
// Created by 刘丰恺 on 17/1/2020.
//

#include "code_gen.h"
#include "code_gens.hpp"

llvm::Value *CodeGen::generate(LLVMCodeGenVisitor *visitor) {
    if (value) {
        return value;
    }

    // save value in visitor.
    GEN_TYPE_AUTO_DOWNCAST(this, visitor);
    return value;
}


llvm::Value *CodeGen::load(llvm::IRBuilder<> &builder, llvm::Value *v) {
    if (v == nullptr) {
        throw create_runtime_error("Load: can't load null ptr.");
    }

    auto *t = v->getType();
    if (t->isPointerTy() && !t->getPointerElementType()->isStructTy()) {
        return builder.CreateLoad(v);
    }

    return v;
}
