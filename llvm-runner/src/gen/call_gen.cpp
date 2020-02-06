//
// Created by 刘丰恺 on 7/2/2020.
//

#include "call_gen.h"

llvm::CallInst *
CallGen::call_func(llvm::IRBuilder<> &builder, llvm::Function *func, std::vector<llvm::Value *> &params) {
    std::vector<llvm::Value *> args_array;
    auto *args = func->arg_begin();
//    console->info("call" + func->getName().str());

    for (auto *i : params) {
        if (args != func->arg_end()) {
            auto *tp = args->getType();
            auto *to = llvm_type_cast(builder, tp, i);
            args_array.push_back(to);
            args++;
//            console->info(llvm_type_dump(to->getType()) + ", ");
        } else if (func->isVarArg()) {
            args_array.push_back(i);
//            console->info(llvm_type_dump(i->getType()) + ", ");
        } else {
            throw std::runtime_error("to many params for " + func->getName().str());
        }
    }
    auto call = builder.CreateCall(func, args_array);

//    llvm::raw_os_ostream os(std::cout);
//    call->print(os);
//    os.flush();

    return call;
}
