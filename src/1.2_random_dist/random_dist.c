#include <raylib.h>

int main(int argc, char const *argv[])
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Nature of Code - Random Distribution");
    
    SetTargetFPS(165);
    const int total_counts = 20;
    // int index = GetRandomValue(0, 19);
    int randomCounts[total_counts];
	int w = screenWidth / total_counts;
    for (int i = 0; i < total_counts; i++)
    {
    	randomCounts[i] = 0;
    }

    while (!WindowShouldClose())
    {
	    int index = GetRandomValue(0, 19);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            randomCounts[index] += 1;
            for (int i = 0; i < total_counts; i++)
            {
            	DrawRectangle(i * w, screenHeight - randomCounts[i], w - 1, randomCounts[i], BLACK);
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
