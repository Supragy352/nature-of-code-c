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
        BeginDrawing();
            drawDot(&walker);
            moveDotV(&walker, randomVector2(-5, 5));
        EndDrawing();

    }
    CloseWindow();
    return 0;
}