//
// Created by 刘丰恺 on 2018/11/4.
//

#include <llvm/IR/Constants.h>
#include "gen/generator_context.h"
#include "generator_literals.h"

llvm::Type *gen::get_llvm_int_type() {
    return llvm::Type::getInt32Ty(llvm_context);
}

llvm::Type *gen::get_llvm_real_type() {
    return llvm::Type::getDoubleTy(llvm_context);
}

llvm::Constant *gen::get_llvm_int(int value) {
    return llvm::ConstantInt::get(get_llvm_int_type(), (uint64_t) value, true);
}

llvm::Constant *gen::get_llvm_real(double value) {
    return llvm::ConstantFP::get(get_llvm_real_type(), value);
}
