//
// Created by 刘丰恺 on 7/2/2020.
//

#ifndef LLVM_RUNNER_STRING_H
#define LLVM_RUNNER_STRING_H

#include "plugin_core.h"
#include "../common/llvm_type.h"
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    HyVarObject ob_base;
    uint64_t length;
    wchar_t *data;
} HyStringObject;

HyVarObject *HNI_StringObject_FromString(const char *str);

HyVarObject *HNI_StringObject_FromSize(size_t len);

HyVarObject *HNI_StringObject_FromHyString(HyStringObject *that);

void HNI_StringObject_Init(HyStringObject *this, char *data, uint64_t length);

void HNI_StringObject_Finalize(HyStringObject *this);

void HNI_StringObject_Print(HyStringObject *this);

#ifdef __cplusplus
}
#endif


#endif //LLVM_RUNNER_STRING_H
