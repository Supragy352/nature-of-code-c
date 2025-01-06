#include <raylib.h>

int main(int argc, char const *argv[])
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Nature of Code - Normal Distribution");
    
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(screenHeight/2, screenWidth/2);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}