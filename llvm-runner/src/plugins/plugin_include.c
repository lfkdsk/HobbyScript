//
// Created by 刘丰恺 on 4/2/2020.
//

#include "tgc.h"

int tgc_exclude() {
    return
            (int) (void *) &tgc_alloc +
            (int) (void *) &tgc_start +
            (int) (void *) &tgc_stop;
}
