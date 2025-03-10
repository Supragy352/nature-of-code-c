#include <raylib.h>

int main(int argc, char const *argv[])
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Hellp");
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello World", GetMouseX(), GetMouseY(), (GetMouseX() + GetMouseY()) * 0.5, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}