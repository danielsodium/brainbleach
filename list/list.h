#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include "../map/map.h"

typedef struct List {
	void** array;
	size_t size;
	size_t capacity;
} List;

List* list_init();
size_t list_size(List* l);

void list_insert(List* l, size_t index);
void list_remove(List* l, size_t index);

void list_destroy(List* l);

#endif
