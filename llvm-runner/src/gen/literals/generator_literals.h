//
// Created by 刘丰恺 on 2018/11/4.
//

#ifndef LLVM_RUNNER_GERENATOR_LITERALS_H
#define LLVM_RUNNER_GERENATOR_LITERALS_H


#include <llvm/IR/Constant.h>

namespace gen {

    llvm::Type *get_llvm_int_type();

    llvm::Type *get_llvm_real_type();

    llvm::Constant *get_llvm_int(int value);

    llvm::Constant *get_llvm_real(double value);
};


#endif //LLVM_RUNNER_GERENATOR_LITERALS_H
