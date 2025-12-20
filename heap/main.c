#include <stdio.h>
#include "heap.h"

void print_heap(Heap* h) {
    printf("[ ");
    for (size_t i = 0; i < h->size; i++) {
        printf("%d ", h->values[i]);
    }
    printf("]\n");
}

int main() {
    Heap* h = min_heap_init();
    min_heap_push(h, 10);
    min_heap_push(h, 20);
    min_heap_push(h, 1);
    min_heap_push(h, 3);
    min_heap_push(h, 100);
    min_heap_push(h, 20);
    print_heap(h);
    min_heap_pop(h);
    print_heap(h);
    min_heap_pop(h);
    print_heap(h);
    min_heap_pop(h);
    print_heap(h);
    min_heap_pop(h);
    print_heap(h);
    min_heap_pop(h);
    print_heap(h);
    min_heap_pop(h);
    print_heap(h);
    min_heap_pop(h);
    print_heap(h);
}
