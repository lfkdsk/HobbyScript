//
// Created by 刘丰恺 on 4/2/2020.
//

#include "tgc.h"
#include "plugin_core.h"

int tgc_exclude() {
    return
            (int) (void *) &tgc_alloc +
            (int) (void *) &tgc_start +
            (int) (void *) &tgc_stop;
}

int plugin_exclude() {
    return
            (int) (void *) &hyobject_malloc +
            (int) (void *) &hyobject_realloc +
            (int) (void *) &start_gc +
            (int) (void *) &stop_gc +
            (int) (void *) &hyobject_free;
}