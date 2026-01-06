#ifndef _MAP_H_
#define _MAP_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct MapNode {
	char* key;
	void* data;
	struct MapNode* next;
} MapNode;

typedef struct {
	MapNode** bins;
	size_t capacity;
} Map;

Map* map_init();
int map_contains(Map* m, char* key);
void map_insert(Map* m, char* key, void* data);
void* map_get(Map* m, char* key);
void map_delete(Map* m, char* key);
void map_destroy(Map* m);

#endif
