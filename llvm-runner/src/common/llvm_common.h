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

static QString llvm_type_dump(llvm::Type *type) {
    if (type->isIntegerTy()) {
        return "i" + QString(llvm::dyn_cast<llvm::IntegerType>(type)->getBitWidth());
    }

    if (type->isPointerTy()) {
        return llvm_type_dump(type->getPointerElementType()) + "_ptr";
    }

    if (type->isStructTy()) {
        auto *ty = llvm::dyn_cast<llvm::StructType>(type);
        std::string n = ty->getName().str();
        return (0 == n.compare(0, 7, "struct.")) ? QString(n.substr(7).c_str()) : QString(n.c_str());
    }

    if (type->isArrayTy()) {
        auto *ty = llvm::dyn_cast<llvm::ArrayType>(type);
        return llvm_type_dump(ty->getElementType()) + "_arr";
    }
    return QString(type->getTypeID());
}

inline static llvm::Function *link_to(llvm::Module *from, llvm::Module *to, llvm::StringRef name) {
    auto size = from->getFunctionList().size();
    auto *f = from->getFunction(name);
    assert(f);
    return llvm::Function::Create(f->getFunctionType(), llvm::GlobalValue::ExternalLinkage, name, to);
}

#endif //LLVM_RUNNER_LLVM_COMMON_H
