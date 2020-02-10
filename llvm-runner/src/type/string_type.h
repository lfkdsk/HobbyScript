//
// Created by 刘丰恺 on 11/2/2020.
//

#ifndef LLVM_RUNNER_STRING_TYPE_H
#define LLVM_RUNNER_STRING_TYPE_H

#include "ast_type.h"
#include "common/type_common.h"

class StringType : public AstType, public TYPE_BASE(StringType) {
public:
    explicit StringType() : AstType(CharactersTyId) {};

    llvm::Type *llvm_type(llvm::LLVMContext &context) override {
        return Plugins::get_struct("HyStringObject");
    }
};


#endif //LLVM_RUNNER_STRING_TYPE_H
