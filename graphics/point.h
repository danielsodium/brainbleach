#pragma once

#include <raylib.h>

Vector2 PointProject(Vector2* screen, Vector3* v);

Vector3 PointRotate(const Vector3* v, const Vector3* theta);
