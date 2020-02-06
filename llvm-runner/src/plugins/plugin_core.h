//
// Created by 刘丰恺 on 6/2/2020.
//

#ifndef LLVM_RUNNER_PLUGIN_CORE_H
#define LLVM_RUNNER_PLUGIN_CORE_H

#include <stddef.h>
#include "tgc.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

static tgc_t gc;

void start_gc();

void stop_gc();

void *hyobject_malloc(size_t size);

void *hyobject_realloc(void *ptr, size_t size);

void hyobject_free(void *ptr);

#ifdef __cplusplus
};
#endif

#endif //LLVM_RUNNER_PLUGIN_CORE_H
