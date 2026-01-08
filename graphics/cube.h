#pragma once

#include "raylib.h"
#include <stdlib.h>

extern const int edges[12][2];

typedef struct {
	Vector3 points[8];
	Vector3 center;
	float length;
	Vector3 rotation;
} Cube;

Cube* CubeInit(Vector3 center, float length);
void CubeDraw(Cube* c, Vector2 screen);
void CubeDestroy(Cube* c);
void CubeRotate(Cube* c, Vector3 theta);
