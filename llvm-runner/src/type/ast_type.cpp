//
// Created by 刘丰恺 on 22/1/2020.
//

#include "ast_type.h"

size_t AstType::hash(size_t h, size_t v) {
    h *= 16777619;
    h ^= v;
    return h;
}

bool AstType::is_instance_of(AstType *type) {
    if (this == type || this->hash_code() == type->hash_code()) {
        return true;
    }
    return (this->inherit ? this->inherit->is_instance_of(type) : false);
}

QString AstType::unique_name() {
    return QString();
}

size_t AstType::hash_code() {
    return type();
}

llvm::Type *AstType::llvm_type(llvm::LLVMContext &context) {
    switch (type()) {
        case VoidTyID:
            return llvm::Type::getVoidTy(context);
        case FloatTyID:
            return llvm::Type::getFloatTy(context);
        case DoubleTyID:
            return llvm::Type::getDoubleTy(context);
        default:
            break;
    }
    return nullptr;
}

uint32_t AstType::type_id() const {
    return this->_type_id;
}

CodeGen *AstType::malloc(AstContext *context) {
    return nullptr;
}

VMTypeID AstType::get_type_id() const {
    return _type_id;
}


