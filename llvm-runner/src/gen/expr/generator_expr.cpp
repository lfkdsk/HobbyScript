//
// Created by 刘丰恺 on 2018/11/4.
//

#include "generator_expr.h"
#include "gen/generator_context.h"

#define GEN_ARITH_OP(op, op_f, name) { \
    return ir_builder.op_f(value_l, value_r, name); \
}


llvm::Value *gen::gen_arith_add(llvm::Value *value_l, llvm::Value *value_r) {
    GEN_ARITH_OP(CreateAdd, CreateFAdd, "add_tmp");
}


llvm::Value *gen::gen_arith_sub(llvm::Value *value_l, llvm::Value *value_r) {
    GEN_ARITH_OP(CreateSub, CreateFSub, "sub_tmp");
}
