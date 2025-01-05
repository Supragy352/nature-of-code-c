#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../include/raylib_extended.h"
#include "../../include/util.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Nature of Code - Random Walker");
    SetTargetFPS(165);
    DOT walker = createDot((Vector2) {screenWidth/2, screenHeight/2});
    
    while (!WindowShouldClose())
    {
        float a = randomFloatBtwFloat(0.0f, 1.0f);
        BeginDrawing();
            drawDot(&walker);
            if (a < 0.4) {
                moveDotV(&walker, (Vector2) {1, 0});    
            } else if (a < 0.6) {
                moveDotV(&walker, (Vector2) {-1, 0});
            } else if (a < 0.8) {
                moveDotV(&walker, (Vector2) {0, 1});
            } else {
                moveDotV(&walker, (Vector2) {0, -1});
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}