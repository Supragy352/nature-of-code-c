#include <raylib.h>
#include "../include/util.h"

int main(int argc, char const *argv[])
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Levy Flight");
    
    SetTargetFPS(60);
    const int total = 20;
    int randomCounts[total] = {0};
    int w = screenWidth / total;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            float x1 = randomFloat(0, 1);
            float probability = x1;
            float x2 = randomFloat(0, 1);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

