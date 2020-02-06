//
// Created by 刘丰恺 on 6/2/2020.
//

#include "plugin_core.h"

void start_gc(int argc) {
    tgc_start(&gc, &argc);
}

void stop_gc() {
    tgc_stop(&gc);
}

void *hyobject_malloc(size_t size) {
    return tgc_alloc(&gc, size);
}

void *hyobject_realloc(void *ptr, size_t size) {
    return tgc_realloc(&gc, ptr, size);
}

void hyobject_free(void *ptr) {
    tgc_free(&gc, ptr);
}