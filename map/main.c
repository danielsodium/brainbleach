#include "map.h"

#include <stdio.h>

int main() {
	Map* m = map_init();
	char* key = "key";
	char* data = "secret!";
	char* key2 = "key2";
	char* data2 = "secret2!";
	char* data3 = "secret3!";
	map_insert(m, key, (void*) data);
	map_insert(m, key2, (void*) data2);
	map_delete(m, key2);
	map_insert(m, key2, (void*) data3);

	printf("Value is: %s\n", (char*) map_get(m, key2));
	map_destroy(m);
}
