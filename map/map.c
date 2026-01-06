#include "map.h"
#include <string.h>

#define MAP_CAPACITY 1024

static size_t hash_function(char* key) {
	size_t hash = 5381;
	int c;

	while ((c = *key++))
		hash = ((hash << 5) + hash) + c;

	return hash % 1024;
}

Map* map_init() {
	Map* m = malloc(sizeof(Map));
	m->capacity = MAP_CAPACITY;
	m->bins= calloc(MAP_CAPACITY, sizeof(MapNode**));
	return m;
}

static MapNode* map_find_node(Map*m, char* key) {
	int hash = hash_function(key);
	MapNode* bin = m->bins[hash];

	// If no other elements in bin
	if (bin == NULL)
		return NULL;

	MapNode* current = bin;
	while (current != NULL) {
	 	if (!strcmp(key, current->key)) {
			return current;
		}
		current = current->next;
	}
	return NULL;
	
}

int map_contains(Map* m, char* key) {
	if (m == NULL || key == NULL) return 0;
	return map_find_node(m, key) == NULL;
}

static MapNode* map_node_create(char* key, void* data) {
	MapNode* new_node = malloc(sizeof(MapNode));
	char* key_str = malloc(strlen(key) * sizeof(char));
	strcpy(key_str, key);
	*new_node = (MapNode) {
		.key = key_str,
		.data = data
	};
	return new_node;
}

void map_insert(Map* m, char* key, void* data) {
	if (m == NULL || key == NULL) return;
	int hash = hash_function(key);
	MapNode* bin = m->bins[hash];

	// If no other elements in bin
	if (bin == NULL) {
		m->bins[hash] = map_node_create(key, data);
		return;
	}

	MapNode* current = bin;
	while (current != NULL) {
		if (!strcmp(key, current->key)) {
			// We already have this key
			// replace the value
			current->data = data;
			return;
		}
		current = current->next;
	}
	// if only one node -> check first node 
	// Need to have current = prev
	current->next = map_node_create(key, data);
}

void* map_get(Map* m, char* key) {
	if (m == NULL || key == NULL) return NULL;
	MapNode* node = map_find_node(m, key);
	return node == NULL ? NULL : node->data;
}

void map_delete(Map* m, char* key) {
	if (m == NULL || key == NULL) return;
	int hash = hash_function(key);
	MapNode* bin = m->bins[hash];

	// If no other elements in bin
	if (bin == NULL) return;
	
	// special case for first element
	if (!strcmp(key, bin->key)) {
		if (bin->next != NULL) {
			m->bins[hash] = bin->next;
		} else {
			m->bins[hash] = NULL;
		}
		free(bin->key);
		free(bin);
		return;
	}

	MapNode* prev = bin;
	MapNode* current = bin->next;
	while (current != NULL) {
	 	if (!strcmp(key, current->key)) {
			if (current->next != NULL) {
				prev->next = current->next;
			}
			free(current->key);
			free(current);
		}
		current = current->next;
	}
	return;
}

void map_destroy(Map* m) {
	if (m == NULL) return;
	for (int i = 0; i < m->capacity; i++) {
		MapNode* next = m->bins[i];
		while (next != NULL) {
			MapNode* temp = next;
			next = temp->next;
			free(next);
		}
	}
	free(m->bins);
}
