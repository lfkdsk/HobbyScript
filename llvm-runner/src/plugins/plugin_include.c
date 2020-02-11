//
// Created by 刘丰恺 on 4/2/2020.
//

#include "gc.h"
#include "plugin_core.h"

int tgc_exclude() {
    return
            (int) (void *) &gc_alloc +
            (int) (void *) &gc_start +
            (int) (void *) &gc_stop;
}

int plugin_exclude() {
    return
            (int) (void *) &hyobject_malloc +
            (int) (void *) &hyobject_realloc +
            (int) (void *) &start_gc +
            (int) (void *) &stop_gc +
            (int) (void *) &hyobject_free;
}