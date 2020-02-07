#ifndef GC_H
#define GC_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <setjmp.h>

enum {
  GC_MARK = 0x01,
  GC_ROOT = 0x02,
  GC_LEAF = 0x04
};

typedef struct {
  void *ptr;
  int flags;
  size_t size, hash;
  void (*dtor)(void*);
} gc_ptr_t;

typedef struct {
  void *bottom;
  int paused;
  uintptr_t minptr, maxptr;
  gc_ptr_t *items, *frees;
  double loadfactor, sweepfactor;
  size_t nitems, nslots, mitems, nfrees;
} gc_t;

void gc_start(gc_t *gc, void *stk);
void gc_stop(gc_t *gc);
void gc_pause(gc_t *gc);
void gc_resume(gc_t *gc);
void gc_run(gc_t *gc);

void *gc_alloc(gc_t *gc, size_t size);
void *gc_calloc(gc_t *gc, size_t num, size_t size);
void *gc_realloc(gc_t *gc, void *ptr, size_t size);
void gc_free(gc_t *gc, void *ptr);

void *gc_alloc_opt(gc_t *gc, size_t size, int flags, void(*dtor)(void*));
void *gc_calloc_opt(gc_t *gc, size_t num, size_t size, int flags, void(*dtor)(void*));

void gc_set_dtor(gc_t *gc, void *ptr, void(*dtor)(void*));
void gc_set_flags(gc_t *gc, void *ptr, int flags);
int gc_get_flags(gc_t *gc, void *ptr);
void(*gc_get_dtor(gc_t *gc, void *ptr))(void*);
size_t gc_get_size(gc_t *gc, void *ptr);

#endif
