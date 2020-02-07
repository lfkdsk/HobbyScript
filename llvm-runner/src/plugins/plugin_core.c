//
// Created by 刘丰恺 on 6/2/2020.
//

#include "plugin_core.h"

void start_gc() {
//    gc_start(&gc, 0);
    printf("hello world");
}

void stop_gc() {
    gc_stop(&gc);
}

void *hyobject_malloc(size_t size) {
    return gc_alloc(&gc, size);
}

void *hyobject_realloc(void *ptr, size_t size) {
    return gc_realloc(&gc, ptr, size);
}

void hyobject_free(void *ptr) {
    gc_free(&gc, ptr);
}