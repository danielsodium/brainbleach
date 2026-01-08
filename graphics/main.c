#include "raylib.h"
#include "cube.h"
#include <math.h>

Vector3 MouseAngles(Vector2* screen) {
    Vector2 mouse = GetMousePosition();
	mouse.x = (((mouse.x - screen->x/2)*2) / screen->x);
	mouse.y = (((mouse.y - screen->y/2)*2) / screen->y);
	return (Vector3) { -sin(mouse.y), sin(mouse.x), 0.0f };
}

int main(void)
{
	const Vector2 screen = {1920, 1080};

    InitWindow(screen.x, screen.y, "weeeeee!");

    SetTargetFPS(60);

	Vector3 center = {0, 0, 0};
	Cube* c = CubeInit(center, 0.5);
    while (!WindowShouldClose())
    {
		if (IsKeyPressed(KEY_H)) {
            if (IsCursorHidden()) ShowCursor();
            else HideCursor();
        }

        BeginDrawing();
        ClearBackground(BLACK);
		CubeRotate(c, MouseAngles(&screen));
		CubeDraw(c, screen);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
