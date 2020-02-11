//
// Created by 刘丰恺 on 7/2/2020.
//

#ifndef LLVM_RUNNER_CALL_GEN_H
#define LLVM_RUNNER_CALL_GEN_H

#include "code_gen.h"
#include "common/utility.h"
#include "runtime/runtime.h"

class CallGen : public CodeGen, public GEN_BASE(CallGen) {
public:
    CallGen() {
        this->runtime_type = CallGenTy;
    }

    static void convert_value(std::vector<llvm::Value *> &vec) {}

    template<typename T1, typename... T2>
    static void convert_value(std::vector<llvm::Value *> &vec, T1 p, T2... arg) {
        vec.push_back(to_llvm_value(llvm_global_context, p));
        convert_value(vec, arg...);
    }

    static llvm::CallInst *
    call_func(llvm::IRBuilder<> &builder, llvm::Function *func, std::vector<llvm::Value *> &params);

    template<typename... Params>
    static llvm::CallInst *call(llvm::IRBuilder<> &builder, llvm::Function *func, Params... func_params) {
        std::vector<llvm::Value *> values;
        convert_value(values, func_params...);
        return CallGen::call_func(builder, func, values);
    }

public:
    CodeGen *object = nullptr;
};


#endif //LLVM_RUNNER_CALL_GEN_H
