#include "point.h"

#include <math.h>

Vector2 PointProject(Vector2 screen, Vector3 pos, Vector3 v) {
	Vector2 projection;
	projection.x = ((((v.x + pos.x)/(v.z + pos.z)) + 1)/2 * screen.y) + (screen.x - screen.y)/2;
	projection.y = (1 - (((v.y + pos.y)/(v.z + pos.z)) + 1)/2) * screen.y;
	return projection;
}

static Vector3 PointRotateY(Vector3 v, const float theta) {
	Vector3 rotated;
	float si = sin(theta);
	float co = cos(theta);
	rotated = (Vector3) {
		.x = (v.x * co) - (v.z * si),
		.y = v.y,
		.z = (v.x * si) + (v.z * co)
	};
	return rotated;
}

static Vector3 PointRotateX(Vector3 v, const float theta) {
	Vector3 rotated;
	float si = sin(theta);
	float co = cos(theta);
	rotated = (Vector3) {
		.x = v.x,
		.y = (v.y * co) - (v.z * si),
		.z = (v.y * si) + (v.z * co)
	};
	return rotated;
}

static Vector3 PointRotateZ(Vector3 v, const float theta) {
	Vector3 rotated;
	float si = sin(theta);
	float co = cos(theta);
	rotated = (Vector3) {
		.x = (v.x * co) - (v.y * si),
		.y = (v.x * si) + (v.y * co),
		.z = v.z
	};
	return rotated;
}

Vector3 PointRotate(const Vector3 v, const Vector3 theta) {
	Vector3 rotated = { v.x, v.y, v.z };
	return PointRotateZ(PointRotateY(PointRotateX(rotated, theta.x), theta.y), theta.z);
}
