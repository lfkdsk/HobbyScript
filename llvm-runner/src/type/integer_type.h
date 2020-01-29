//
// Created by 刘丰恺 on 22/1/2020.
//

#ifndef LLVM_RUNNER_INTEGER_TYPE_H
#define LLVM_RUNNER_INTEGER_TYPE_H

#include "ast_type.h"

class IntegerType : public AstType {
public:
    IntegerType(int bit_width, bool is_unsigned);

public:
    int bit_width;
    bool is_unsigned = false;
public:
    static IntegerType *get(int bit_width, bool is_unsigned = false);

    QString unique_name();
};


#endif //LLVM_RUNNER_INTEGER_TYPE_H
