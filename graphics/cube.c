#include "cube.h"
#include "point.h"

const int edges[12][2] = {{0, 1}, {1, 2}, {2, 3}, {3,0},
						  {4, 5}, {5, 6}, {6, 7}, {7,4},
						  {0, 4}, {1, 5}, {2, 6}, {3,7}};

static void GeneratePoints(Cube* c) {
    float half = c->length / 2;
    c->points[0] = (Vector3) { c->center.x - half, c->center.y - half, c->center.z + half};
    c->points[1] = (Vector3) { c->center.x + half, c->center.y - half, c->center.z + half};
    c->points[2] = (Vector3) { c->center.x + half, c->center.y + half, c->center.z + half};
    c->points[3] = (Vector3) { c->center.x - half, c->center.y + half, c->center.z + half};

    c->points[4] = (Vector3) { c->center.x - half, c->center.y - half, c->center.z - half};
    c->points[5] = (Vector3) { c->center.x + half, c->center.y - half, c->center.z - half};
    c->points[6] = (Vector3) { c->center.x + half, c->center.y + half, c->center.z - half};
    c->points[7] = (Vector3) { c->center.x - half, c->center.y + half, c->center.z - half};
}

Cube* CubeInit(Vector3 pos, float length) {
	Cube* c = malloc(sizeof(Cube));
	*c = (Cube) {
		.center = {0.0f, 0.0f, 0.0f},
		.position = pos,
		.length = length,
		.rotation = 0,
	};

	GeneratePoints(c);
	return c;
}

void CubeDraw(Cube* c, Vector2 screen) {
	Vector2 rotated[8];
	for (int i = 0; i < 8; i++)
		rotated[i] = PointProject(screen, c->position, PointRotate(c->points[i], c->rotation));

	for (int i = 0; i < 12; i++) {
		Vector2 p1 = rotated[edges[i][0]];
		Vector2 p2 = rotated[edges[i][1]];
		DrawLine(p1.x, p1.y, p2.x, p2.y, WHITE);
	}
}

void CubeRotate(Cube* c, Vector3 theta) {
	c->rotation = theta;
}

void CubeDestroy(Cube* c) {
	free(c);
}
