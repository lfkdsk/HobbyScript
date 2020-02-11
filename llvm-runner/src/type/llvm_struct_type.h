//
// Created by 刘丰恺 on 10/2/2020.
//

#ifndef LLVM_RUNNER_LLVM_STRUCT_TYPE_H
#define LLVM_RUNNER_LLVM_STRUCT_TYPE_H

#include "ast_type.h"
#include "runtime/plugins.h"

class LLVMStructType : public AstType, public TYPE_BASE(LLVMStructType) {
public:
    explicit LLVMStructType(const QString &name) : type(Plugins::get_struct(name)), AstType(StructTyID) {};

    explicit LLVMStructType(llvm::StructType *type) : type(type), AstType(StructTyID) {};

private:
    llvm::StructType *type;

public:
    llvm::StructType *llvm_type() const {
        return type;
    }
};


#endif //LLVM_RUNNER_LLVM_STRUCT_TYPE_H
