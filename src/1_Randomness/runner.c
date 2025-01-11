#include <raylib.h>

int main(int argc, char const *argv[])
{
    const int screenWidth = 100;
    const int screenHeight = 100;

    InitWindow(screenWidth, screenHeight, "Blah");
    
    SetTargetFPS(120);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(50, 50);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}