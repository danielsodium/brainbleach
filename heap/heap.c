#include "heap.h"

#include <stdlib.h>

static size_t get_parent(size_t i) {
    if (i == 0) return 0;
    return (i - 1)/2;
}

static size_t get_left(size_t i) {
    return 2*i + 1;
}
static size_t get_right(size_t i) {
    return 2*i + 2;
}

static Heap* heap_init() {
    Heap* h = malloc(sizeof(Heap));
    h->size = 0;
    h->capacity = 1;
    h->values = malloc(h->capacity * sizeof(int));
}

Heap* max_heap_init() {
    return heap_init();
}
Heap* min_heap_init() {
    return heap_init();
}

void max_heap_push(Heap* h, int value) {
    if (h->size >= h->capacity) {
        h->capacity *= 2;
        h->values = realloc(h->values, h->capacity * sizeof(int));
    }
    h->values[h->size] = value;
    // Percolate up
    size_t current = h->size;
    size_t parent = get_parent(current);
    while (current != parent) {
        if (h->values[parent] >= value) break;
        h->values[current] = h->values[parent];
        h->values[parent] = value;
        current = parent;
        parent = get_parent(parent);
    }
    h->size++;
}

void min_heap_push(Heap* h, int value) {
    if (h->size >= h->capacity) {
        h->capacity *= 2;
        h->values = realloc(h->values, h->capacity * sizeof(int));
    }
    h->values[h->size] = value;
    // Percolate up
    size_t current = h->size;
    size_t parent = get_parent(current);
    while (current != parent) {
        if (h->values[parent] <= value) break;
        h->values[current] = h->values[parent];
        h->values[parent] = value;
        current = parent;
        parent = get_parent(parent);
    }
    h->size++;
}

int max_heap_pop(Heap* h) {
    if (h->size == 0) return -1; 
    int popped = h->values[0];

    // swap first and last element
    h->values[0] = h->values[h->size-1];

    // percolate down
    size_t current = 0;
    size_t left = get_left(current);
    size_t right = get_right(current);
    while (left < h->size) {
        if (h->values[left] > h->values[current] &&
            h->values[left] >= h->values[right]) {
            size_t t = h->values[left];
            h->values[left] = h->values[current];
            h->values[current] = t;
            current = left;
        } else if (h->values[right] > h->values[current] &&
                   h->values[right] >= h->values[left]) {
            size_t t = h->values[right];
            h->values[right] = h->values[current];
            h->values[current] = t;
            current = right;
        } else {
            break;
        }
        left = get_left(current);
        right = get_right(current);
    }

    h->size--;
    return popped;
}

int min_heap_pop(Heap* h) {
    if (h->size == 0) return -1; 
    int popped = h->values[0];

    // swap first and last element
    h->values[0] = h->values[h->size-1];

    // percolate down
    size_t current = 0;
    size_t left = get_left(current);
    size_t right = get_right(current);
    while (left < h->size) {
        if (h->values[left] < h->values[current] &&
            h->values[left] <= h->values[right]) {
            size_t t = h->values[left];
            h->values[left] = h->values[current];
            h->values[current] = t;
            current = left;
        } else if (h->values[right] < h->values[current] &&
                   h->values[right] <= h->values[left]) {
            size_t t = h->values[right];
            h->values[right] = h->values[current];
            h->values[current] = t;
            current = right;
        } else {
            break;
        }
        left = get_left(current);
        right = get_right(current);
    }

    h->size--;
    return popped;
}

void max_heap_destroy(Heap* h) {
    free(h->values);
    free(h);
}

void min_heap_destroy(Heap* h) {
    free(h->values);
    free(h);
}
