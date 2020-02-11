//
// Created by 刘丰恺 on 23/1/2020.
//

#ifndef LLVM_RUNNER_CLASS_TYPE_H
#define LLVM_RUNNER_CLASS_TYPE_H

#include "ast_type.h"

class ClassType : public AstType, public TYPE_BASE(ClassType) {
public:
    QVector<AstType *> template_vars;
    AstContext *context = nullptr;
};


#endif //LLVM_RUNNER_CLASS_TYPE_H
