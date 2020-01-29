//
// Created by 刘丰恺 on 30/1/2020.
//

#ifndef LLVM_RUNNER_LLVM_COMMON_H
#define LLVM_RUNNER_LLVM_COMMON_H

#include "common.h"


static llvm::Value *llvm_type_cast(llvm::IRBuilder<> &builder, llvm::Type *dest, llvm::Value *v) {
    if (!dest || !v) return v;
    llvm::Type *r = v->getType();
    if (r == dest)
        return v;

    if (dest->isIntegerTy() && r->isIntegerTy()) {
        return builder.CreateSExtOrTrunc(v, dest);
    } else if (dest->isFloatingPointTy() && r->isFloatingPointTy()) {
        if (dest->getIntegerBitWidth() > r->getIntegerBitWidth()) {
            return builder.CreateFPExt(v, dest);
        } else if (dest->getIntegerBitWidth() < r->getIntegerBitWidth()) {
            return builder.CreateFPTrunc(v, dest);
        } else {
            return v;
        }
    } else if (dest->isIntegerTy() && r->isFloatingPointTy()) {
        return builder.CreateFPToSI(v, dest);
    } else if (dest->isFloatingPointTy() && r->isIntegerTy()) {
        return builder.CreateSIToFP(v, dest);
    }

    if (r->isPointerTy()) {
        r = r->getPointerElementType();
        if (r == dest)
            return builder.CreateLoad(v);
        if (r->isStructTy()) {
//            return structCast(builder, dest, v);
        }
    }

    return builder.CreateBitOrPointerCast(v, dest);
}

#endif //LLVM_RUNNER_LLVM_COMMON_H
