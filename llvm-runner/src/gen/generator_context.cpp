//
// Created by 刘丰恺 on 2018/11/4.
//

#include "generator_context.h"

llvm::LLVMContext llvm_context;
llvm::Module llvm_module("hobby_script", llvm_context);
llvm::DataLayout llvm_data(&llvm_module);
llvm::IRBuilder<> ir_builder(llvm_context);
generator_context gen_env;

const generator_id_context &generator_context::get_id_context() const {
    return id_context;
}

void generator_context::push() {

}

void generator_context::pop() {

}
