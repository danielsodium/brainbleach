#include "list.h"

List* list_init() {
	List* l = malloc(sizeof(List));
	Map* m = map_init();
	*l = (List) {
		.head = NULL,
		.tail = NULL,
		.indicies = m,
		.size = 0
	};
	return l;
}

size_t list_size(List* l) {
	return l->size;
}

list_get() {
}

void list_insert(List* l, size_t index) {

}
void list_remove(List* l, size_t index) {

}



void list_destroy(List* l) {
	map_destroy(l->indicies);
	free(l);
}
