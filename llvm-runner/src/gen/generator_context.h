//
// Created by 刘丰恺 on 2018/11/4.
//

#ifndef LLVM_RUNNER_GENERATOR_CONTENT_H
#define LLVM_RUNNER_GENERATOR_CONTENT_H


#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/DataLayout.h>
#include <llvm/IR/IRBuilder.h>
#include <gen/value/generator_id_context.h>

class generator_context {
public:
    const generator_id_context &get_id_context() const;

    void push();

    void pop();

private:
    generator_id_context id_context;
};

extern llvm::LLVMContext llvm_context;
extern llvm::Module llvm_module;
extern llvm::DataLayout llvm_data;
extern llvm::IRBuilder<> ir_builder;
extern generator_context gen_env;


#endif //LLVM_RUNNER_GENERATOR_CONTENT_H
