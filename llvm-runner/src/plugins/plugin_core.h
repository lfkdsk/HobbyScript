//
// Created by 刘丰恺 on 6/2/2020.
//

#ifndef LLVM_RUNNER_PLUGIN_CORE_H
#define LLVM_RUNNER_PLUGIN_CORE_H

#include <stddef.h>
#include "gc.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

static gc_t gc;

void init_log();

void start_gc(int argc);

void stop_gc();

void *hyobject_malloc(size_t size);

void *hyobject_realloc(void *ptr, size_t size);

void hyobject_free(void *ptr);

#ifdef __cplusplus
};
#endif

#endif //LLVM_RUNNER_PLUGIN_CORE_H
