#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
const int screenWidth = 1920;
const int screenHeight = 1200;

const int total_counts = 20;
int randomCounts[total_counts];
int w = screenWidth / total_counts;

static void InitGame(void);
static void Update(void);

int main(void)
{
    srand(time(NULL));
    InitWindow(screenWidth, screenHeight, "Nature of Code - Random Walker");
    InitGame();
    
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(Update, 60, 1);
#else
    SetTargetFPS(165);

    while (!WindowShouldClose())
    {
        Update();
    }
#endif
    CloseWindow();
    return 0;
}

void InitGame(void)
{
    for (int i = 0; i < total_counts; i++)
    {
        randomCounts[i] = 0;
    }

}

void Update(void)
{
    BeginDrawing();
        int index = GetRandomValue(0, 19);
        ClearBackground(RAYWHITE);
        randomCounts[index] += 1;
            for (int i = 0; i < total_counts; i++)
            {
                DrawRectangle(i * w, screenHeight - randomCounts[i], w - 1, randomCounts[i], BLACK);
            }
    EndDrawing();
}
