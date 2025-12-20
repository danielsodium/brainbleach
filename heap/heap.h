#ifndef _HEAP_H_
#define _HEAP_H_

#include <stddef.h>

typedef struct {
    int* values; 
    size_t size;
    size_t capacity;
} Heap;

Heap* max_heap_init();
void max_heap_push(Heap* h, int value);
int max_heap_pop(Heap* h);
void max_heap_destroy(Heap* h);

Heap* min_heap_init();
void min_heap_push(Heap* h, int value);
int min_heap_pop(Heap* h);
void min_heap_destroy(Heap* h);

#endif
