//
// Created by 刘丰恺 on 4/2/2020.
//

#ifndef LLVM_RUNNER_CPLUGINS_H
#define LLVM_RUNNER_CPLUGINS_H


#include "common/common.h"
#include "runtime.h"

class CPlugins {
public:
    static llvm::Module *load_llvm_ir(const QString& ir_file_name);
};


#endif //LLVM_RUNNER_CPLUGINS_H
