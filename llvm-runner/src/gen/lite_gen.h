//
// Created by 刘丰恺 on 30/1/2020.
//

#ifndef LLVM_RUNNER_LITE_GEN_H
#define LLVM_RUNNER_LITE_GEN_H

#include "code_gen.h"

class StringLiteGen : public CodeGen, public GEN_BASE(StringLiteGen) {
public:
    StringLiteGen(llvm::LLVMContext &llvm_context, QString string) :
            llvm_context(llvm_context),
            source_string(std::move(string)) {
        this->runtime_type = StringLiteGenTy;
    }

public:
    llvm::LLVMContext &context() {
        return llvm_context;
    }

    QString str() {
        return source_string;
    }

private:
    llvm::LLVMContext &llvm_context;
    QString source_string;
};


#endif //LLVM_RUNNER_LITE_GEN_H
