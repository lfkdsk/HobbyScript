//
// Created by 刘丰恺 on 6/2/2020.
//

#ifndef LLVM_RUNNER_PLUGIN_CORE_H
#define LLVM_RUNNER_PLUGIN_CORE_H

#include <stddef.h>
#include <assert.h>
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

typedef struct {
    ssize_t ob_size;
    int64_t ob_type_id;
} HyVarObject;

#define _HyVarObject_CAST(op) ((HyVarObject*)(op))

#define Hy_TYPE(ob) (_HyVarObject_CAST(ob)->ob_type_id)
#define Hy_SIZE(ob) (_HyVarObject_CAST(ob)->ob_size)

static inline HyVarObject *_HyObject_INIT_VAR(HyVarObject *op, int32_t type_id, ssize_t size) {
    assert(op != NULL);
    Hy_SIZE(op) = size;
    Hy_TYPE(op) = type_id;
    return op;
}

#define HyObject_INIT_VAR(op, type_id, size) \
    _HyObject_INIT_VAR(_HyVarObject_CAST(op), (type_id), (size))

#ifdef __cplusplus
};
#endif

#endif //LLVM_RUNNER_PLUGIN_CORE_H
