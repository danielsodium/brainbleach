#include "point.h"

#include <math.h>

Vector2 PointProject(Vector2* screen, Vector3* v) {
	Vector2 projection;
	projection.x = (((v->x/(v->z+1)) + 1)/2 * screen->y) + (screen->x - screen->y)/2;
	projection.y = (1 - ((v->y/(v->z+1)) + 1)/2) * screen->y;
	return projection;
}

static void PointRotateY(Vector3* v, const float theta) {
	float si = sin(theta);
	float co = cos(theta);
	float x = v->x;
	float z = v->z;
	v->x = (x * co) - (z * si);
	v->z = (x * si) + (z * co);
}

static void PointRotateX(Vector3* v, const float theta) {
	float si = sin(theta);
	float co = cos(theta);
	float y = v->y;
	float z = v->z;
	v->y = (y * co) - (z * si);
	v->z = (y * si) + (z * co);
}

static void PointRotateZ(Vector3* v, const float theta) {
	float si = sin(theta);
	float co = cos(theta);
	float x = v->x;
	float y = v->y;
	v->x = (x * co) - (y * si);
	v->y = (x * si) + (y * co);
}


Vector3 PointRotate(const Vector3* v, const Vector3* theta) {
	Vector3 rotated = { v->x, v->y, v->z };
	PointRotateX(&rotated, theta->x);
	PointRotateY(&rotated, theta->y);
	PointRotateZ(&rotated, theta->z);
	return rotated;
}
