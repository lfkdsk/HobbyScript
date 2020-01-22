//
// Created by 刘丰恺 on 22/1/2020.
//

#ifndef LLVM_RUNNER_AUTO_TYPE_H
#define LLVM_RUNNER_AUTO_TYPE_H

#include "ast_type.h"

class AutoType : public AstType {
public:
    explicit AutoType() : AstType(AutoTyId) {};
};


#endif //LLVM_RUNNER_AUTO_TYPE_H
