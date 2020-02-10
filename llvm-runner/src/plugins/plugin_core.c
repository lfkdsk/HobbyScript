//
// Created by 刘丰恺 on 6/2/2020.
//

#include "plugin_core.h"

void init_log() {
    printf("init plugin core");
}

void start_gc(int argc) {
    int i = 0;
    gc_start(&gc, &i);
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