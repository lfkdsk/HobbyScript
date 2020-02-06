//
// Created by 刘丰恺 on 7/2/2020.
//

#ifndef LLVM_RUNNER_CALL_GEN_H
#define LLVM_RUNNER_CALL_GEN_H

#include "code_gen.h"
#include "common/utility.h"

class CallGen : public CodeGen, public GEN_BASE(CallGen) {
public:
    CallGen() {
        this->runtime_type = CallGenTy;
    }

    template<typename T1, typename... T2>
    static void convert_value(std::vector<llvm::Value *> &vec, T1 p, T2... arg) {
        vec.push_back(to_llvm_value(p));
        convert_value(vec, arg...);
    }

    static void convert_value(std::vector<llvm::Value *> &vec) {}

    static llvm::CallInst *
    call_func(llvm::IRBuilder<> &builder, llvm::Function *func, std::vector<llvm::Value *> &params);

    template<class... Params>
    static llvm::CallInst *call(llvm::IRBuilder<> &builder, llvm::Function *func, Params... func_params) {
        std::vector<llvm::Value *> values;
        convert_value(values, func_params...);

        std::vector<llvm::Value *> args_array;
        auto args = func->arg_begin();

        for (auto *i : values) {
            if (args != func->arg_end()) {
                auto *tp = args->getType();
                auto *to = llvm_type_cast(builder, tp, i);
                args_array.push_back(to);
                args++;
            } else if (func->isVarArg()) {
                args_array.push_back(i);
            } else {
                throw std::runtime_error("to many params for " + func->getName().str());
            }
        }
        auto call = builder.CreateCall(func, args_array);
//
//        llvm::raw_os_ostream os(std::cout);
//        call->print(os);
//        os.flush();

        return call;
//        return CallGen::call_func(builder, func, values);
    }
};


#endif //LLVM_RUNNER_CALL_GEN_H
