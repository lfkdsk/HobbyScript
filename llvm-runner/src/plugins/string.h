//
// Created by 刘丰恺 on 7/2/2020.
//

#ifndef LLVM_RUNNER_STRING_H
#define LLVM_RUNNER_STRING_H

#include "plugin_core.h"
#include <QString>

typedef struct {
    HyVarObject ob_base
    uint64_t length;
    wchar_t *data;
} HyStringObject;


#endif //LLVM_RUNNER_STRING_H
