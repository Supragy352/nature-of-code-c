#include "util.h"
#include <math.h>
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// #include "../../include/raylib_extended.h"

#define samples 1000

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    
    const float pi = 3.14159265;

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Nature of Code - Normal Distribution");
    
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            for (int i = 0; i < samples; ++i)
            {
                DrawCircle((float)screenWidth/2 + randomGaussian(0, 1) * 300, 500, 20.0f, (Color) {0,0,0,10});
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
