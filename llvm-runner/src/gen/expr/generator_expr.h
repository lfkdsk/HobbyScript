//
// Created by 刘丰恺 on 2018/11/4.
//

#ifndef LLVM_RUNNER_GENERATOR_EXPR_H
#define LLVM_RUNNER_GENERATOR_EXPR_H


#include <llvm/IR/Value.h>

namespace gen {

    llvm::Value *gen_arith_add(llvm::Value *value_l, llvm::Value *value_r);

    llvm::Value *gen_arith_sub(llvm::Value *value_l, llvm::Value *value_r);
}

#endif //LLVM_RUNNER_GENERATOR_EXPR_H
