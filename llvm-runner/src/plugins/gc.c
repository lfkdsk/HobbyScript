#include "gc.h"

static size_t gc_hash(void *ptr) {
    return ((uintptr_t) ptr) >> 3;
}

static size_t gc_probe(gc_t *gc, size_t i, size_t h) {
    long v = i - (h - 1);
    if (v < 0) { v = gc->nslots + v; }
    return v;
}

static gc_ptr_t *gc_get_ptr(gc_t *gc, void *ptr) {
    size_t i, j, h;
    i = gc_hash(ptr) % gc->nslots;
    j = 0;
    while (1) {
        h = gc->items[i].hash;
        if (h == 0 || j > gc_probe(gc, i, h)) { return NULL; }
        if (gc->items[i].ptr == ptr) { return &gc->items[i]; }
        i = (i + 1) % gc->nslots;
        j++;
    }
    return NULL;
}

static void gc_add_ptr(
        gc_t *gc, void *ptr, size_t size,
        int flags, void(*dtor)(void *)) {

    gc_ptr_t item, tmp;
    size_t h, p, i, j;

    i = gc_hash(ptr) % gc->nslots;
    j = 0;

    item.ptr = ptr;
    item.flags = flags;
    item.size = size;
    item.hash = i + 1;
    item.dtor = dtor;

    while (1) {
        h = gc->items[i].hash;
        if (h == 0) {
            gc->items[i] = item;
            return;
        }
        if (gc->items[i].ptr == item.ptr) { return; }
        p = gc_probe(gc, i, h);
        if (j >= p) {
            tmp = gc->items[i];
            gc->items[i] = item;
            item = tmp;
            j = p;
        }
        i = (i + 1) % gc->nslots;
        j++;
    }

}

static void gc_rem_ptr(gc_t *gc, void *ptr) {

    size_t i, j, h, nj, nh;

    if (gc->nitems == 0) { return; }

    for (i = 0; i < gc->nfrees; i++) {
        if (gc->frees[i].ptr == ptr) { gc->frees[i].ptr = NULL; }
    }

    i = gc_hash(ptr) % gc->nslots;
    j = 0;

    while (1) {
        h = gc->items[i].hash;
        if (h == 0 || j > gc_probe(gc, i, h)) { return; }
        if (gc->items[i].ptr == ptr) {
            memset(&gc->items[i], 0, sizeof(gc_ptr_t));
            j = i;
            while (1) {
                nj = (j + 1) % gc->nslots;
                nh = gc->items[nj].hash;
                if (nh != 0 && gc_probe(gc, nj, nh) > 0) {
                    memcpy(&gc->items[j], &gc->items[nj], sizeof(gc_ptr_t));
                    memset(&gc->items[nj], 0, sizeof(gc_ptr_t));
                    j = nj;
                } else {
                    break;
                }
            }
            gc->nitems--;
            return;
        }
        i = (i + 1) % gc->nslots;
        j++;
    }

}


enum {
    GC_PRIMES_COUNT = 24
};

static const size_t gc_primes[GC_PRIMES_COUNT] = {
        0, 1, 5, 11,
        23, 53, 101, 197,
        389, 683, 1259, 2417,
        4733, 9371, 18617, 37097,
        74093, 148073, 296099, 592019,
        1100009, 2200013, 4400021, 8800019
};

static size_t gc_ideal_size(gc_t *gc, size_t size) {
    size_t i, last;
    size = (size_t) ((double) (size + 1) / gc->loadfactor);
    for (i = 0; i < GC_PRIMES_COUNT; i++) {
        if (gc_primes[i] >= size) { return gc_primes[i]; }
    }
    last = gc_primes[GC_PRIMES_COUNT - 1];
    for (i = 0;; i++) {
        if (last * i >= size) { return last * i; }
    }
    return 0;
}

static int gc_rehash(gc_t *gc, size_t new_size) {

    size_t i;
    gc_ptr_t *old_items = gc->items;
    size_t old_size = gc->nslots;

    gc->nslots = new_size;
    gc->items = calloc(gc->nslots, sizeof(gc_ptr_t));

    if (gc->items == NULL) {
        gc->nslots = old_size;
        gc->items = old_items;
        return 0;
    }

    for (i = 0; i < old_size; i++) {
        if (old_items[i].hash != 0) {
            gc_add_ptr(gc,
                       old_items[i].ptr, old_items[i].size,
                       old_items[i].flags, old_items[i].dtor);
        }
    }

    free(old_items);

    return 1;
}

static int gc_resize_more(gc_t *gc) {
    size_t new_size = gc_ideal_size(gc, gc->nitems);
    size_t old_size = gc->nslots;
    return (new_size > old_size) ? gc_rehash(gc, new_size) : 1;
}

static int gc_resize_less(gc_t *gc) {
    size_t new_size = gc_ideal_size(gc, gc->nitems);
    size_t old_size = gc->nslots;
    return (new_size < old_size) ? gc_rehash(gc, new_size) : 1;
}

static void gc_mark_ptr(gc_t *gc, void *ptr) {

    size_t i, j, h, k;

    if ((uintptr_t) ptr < gc->minptr
        || (uintptr_t) ptr > gc->maxptr) { return; }

    i = gc_hash(ptr) % gc->nslots;
    j = 0;

    while (1) {
        h = gc->items[i].hash;
        if (h == 0 || j > gc_probe(gc, i, h)) { return; }
        if (ptr == gc->items[i].ptr) {
            if (gc->items[i].flags & GC_MARK) { return; }
            gc->items[i].flags |= GC_MARK;
            if (gc->items[i].flags & GC_LEAF) { return; }
            for (k = 0; k < gc->items[i].size / sizeof(void *); k++) {
                gc_mark_ptr(gc, ((void **) gc->items[i].ptr)[k]);
            }
            return;
        }
        i = (i + 1) % gc->nslots;
        j++;
    }

}

static void gc_mark_stack(gc_t *gc) {

    void *stk, *bot, *top, *p;
    bot = gc->bottom;
    top = &stk;

    if (bot == top) { return; }

    if (bot < top) {
        for (p = top; p >= bot; p = ((char *) p) - sizeof(void *)) {
            gc_mark_ptr(gc, *((void **) p));
        }
    }

    if (bot > top) {
        for (p = top; p <= bot; p = ((char *) p) + sizeof(void *)) {
            gc_mark_ptr(gc, *((void **) p));
        }
    }

}

static void gc_mark(gc_t *gc) {

    size_t i, k;
    jmp_buf env;
    void (*volatile mark_stack)(gc_t *) = gc_mark_stack;

    if (gc->nitems == 0) { return; }

    for (i = 0; i < gc->nslots; i++) {
        if (gc->items[i].hash == 0) { continue; }
        if (gc->items[i].flags & GC_MARK) { continue; }
        if (gc->items[i].flags & GC_ROOT) {
            gc->items[i].flags |= GC_MARK;
            if (gc->items[i].flags & GC_LEAF) { continue; }
            for (k = 0; k < gc->items[i].size / sizeof(void *); k++) {
                gc_mark_ptr(gc, ((void **) gc->items[i].ptr)[k]);
            }
            continue;
        }
    }

    memset(&env, 0, sizeof(jmp_buf));
    setjmp(env);
    mark_stack(gc);

}

void gc_sweep(gc_t *gc) {

    size_t i, j, k, nj, nh;

    if (gc->nitems == 0) { return; }

    gc->nfrees = 0;
    for (i = 0; i < gc->nslots; i++) {
        if (gc->items[i].hash == 0) { continue; }
        if (gc->items[i].flags & GC_MARK) { continue; }
        if (gc->items[i].flags & GC_ROOT) { continue; }
        gc->nfrees++;
    }

    gc->frees = realloc(gc->frees, sizeof(gc_ptr_t) * gc->nfrees);
    if (gc->frees == NULL) { return; }

    i = 0;
    k = 0;
    while (i < gc->nslots) {
        if (gc->items[i].hash == 0) {
            i++;
            continue;
        }
        if (gc->items[i].flags & GC_MARK) {
            i++;
            continue;
        }
        if (gc->items[i].flags & GC_ROOT) {
            i++;
            continue;
        }

        gc->frees[k] = gc->items[i];
        k++;
        memset(&gc->items[i], 0, sizeof(gc_ptr_t));

        j = i;
        while (1) {
            nj = (j + 1) % gc->nslots;
            nh = gc->items[nj].hash;
            if (nh != 0 && gc_probe(gc, nj, nh) > 0) {
                memcpy(&gc->items[j], &gc->items[nj], sizeof(gc_ptr_t));
                memset(&gc->items[nj], 0, sizeof(gc_ptr_t));
                j = nj;
            } else {
                break;
            }
        }
        gc->nitems--;
    }

    for (i = 0; i < gc->nslots; i++) {
        if (gc->items[i].hash == 0) { continue; }
        if (gc->items[i].flags & GC_MARK) {
            gc->items[i].flags &= ~GC_MARK;
        }
    }

    gc_resize_less(gc);

    gc->mitems = gc->nitems + (size_t) (gc->nitems * gc->sweepfactor) + 1;

    for (i = 0; i < gc->nfrees; i++) {
        if (gc->frees[i].ptr) {
            if (gc->frees[i].dtor) { gc->frees[i].dtor(gc->frees[i].ptr); }
            free(gc->frees[i].ptr);
        }
    }

    free(gc->frees);
    gc->frees = NULL;
    gc->nfrees = 0;

}

void gc_start(gc_t *gc, void *stk) {
    gc->bottom = stk;
    gc->paused = 0;
    gc->nitems = 0;
    gc->nslots = 0;
    gc->mitems = 0;
    gc->nfrees = 0;
    gc->maxptr = 0;
    gc->items = NULL;
    gc->frees = NULL;
    gc->minptr = UINTPTR_MAX;
    gc->loadfactor = 0.9;
    gc->sweepfactor = 0.5;
}

void gc_stop(gc_t *gc) {
    gc_sweep(gc);
    free(gc->items);
    free(gc->frees);
}

void gc_pause(gc_t *gc) {
    gc->paused = 1;
}

void gc_resume(gc_t *gc) {
    gc->paused = 0;
}

void gc_run(gc_t *gc) {
    gc_mark(gc);
    gc_sweep(gc);
}

static void *gc_add(
        gc_t *gc, void *ptr, size_t size,
        int flags, void(*dtor)(void *)) {

    gc->nitems++;
    gc->maxptr = ((uintptr_t) ptr) + size > gc->maxptr ?
                 ((uintptr_t) ptr) + size : gc->maxptr;
    gc->minptr = ((uintptr_t) ptr) < gc->minptr ?
                 ((uintptr_t) ptr) : gc->minptr;

    if (gc_resize_more(gc)) {
        gc_add_ptr(gc, ptr, size, flags, dtor);
        if (!gc->paused && gc->nitems > gc->mitems) {
            gc_run(gc);
        }
        return ptr;
    } else {
        gc->nitems--;
        free(ptr);
        return NULL;
    }
}

static void gc_rem(gc_t *gc, void *ptr) {
    gc_rem_ptr(gc, ptr);
    gc_resize_less(gc);
    gc->mitems = gc->nitems + gc->nitems / 2 + 1;
}

void *gc_alloc(gc_t *gc, size_t size) {
    return gc_alloc_opt(gc, size, 0, NULL);
}

void *gc_calloc(gc_t *gc, size_t num, size_t size) {
    return gc_calloc_opt(gc, num, size, 0, NULL);
}

void *gc_realloc(gc_t *gc, void *ptr, size_t size) {

    gc_ptr_t *p;
    void *qtr = realloc(ptr, size);

    if (qtr == NULL) {
        gc_rem(gc, ptr);
        return qtr;
    }

    if (ptr == NULL) {
        gc_add(gc, qtr, size, 0, NULL);
        return qtr;
    }

    p = gc_get_ptr(gc, ptr);

    if (p && qtr == ptr) {
        p->size = size;
        return qtr;
    }

    if (p && qtr != ptr) {
        int flags = p->flags;
        void (*dtor)(void *) = p->dtor;
        gc_rem(gc, ptr);
        gc_add(gc, qtr, size, flags, dtor);
        return qtr;
    }

    return NULL;
}

void gc_free(gc_t *gc, void *ptr) {
    gc_ptr_t *p = gc_get_ptr(gc, ptr);
    if (p) {
        if (p->dtor) {
            p->dtor(ptr);
        }
        free(ptr);
        gc_rem(gc, ptr);
    }
}

void *gc_alloc_opt(gc_t *gc, size_t size, int flags, void(*dtor)(void *)) {
    void *ptr = malloc(size);
    if (ptr != NULL) {
        ptr = gc_add(gc, ptr, size, flags, dtor);
    }
    return ptr;
}

void *gc_calloc_opt(
        gc_t *gc, size_t num, size_t size,
        int flags, void(*dtor)(void *)) {
    void *ptr = calloc(num, size);
    if (ptr != NULL) {
        ptr = gc_add(gc, ptr, num * size, flags, dtor);
    }
    return ptr;
}

void gc_set_dtor(gc_t *gc, void *ptr, void(*dtor)(void *)) {
    gc_ptr_t *p = gc_get_ptr(gc, ptr);
    if (p) { p->dtor = dtor; }
}

void gc_set_flags(gc_t *gc, void *ptr, int flags) {
    gc_ptr_t *p = gc_get_ptr(gc, ptr);
    if (p) { p->flags = flags; }
}

int gc_get_flags(gc_t *gc, void *ptr) {
    gc_ptr_t *p = gc_get_ptr(gc, ptr);
    if (p) { return p->flags; }
    return 0;
}

void (*gc_get_dtor(gc_t *gc, void *ptr))(void *) {
    gc_ptr_t *p = gc_get_ptr(gc, ptr);
    if (p) { return p->dtor; }
    return NULL;
}

size_t gc_get_size(gc_t *gc, void *ptr) {
    gc_ptr_t *p = gc_get_ptr(gc, ptr);
    if (p) { return p->size; }
    return 0;
}
