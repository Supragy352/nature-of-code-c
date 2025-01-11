#include <math.h>
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
// #include "../../include/raylib_extended.h"

#define samples 1000

int main(int argc, char const *argv[])
{
    float sample1[samples] = {0};
    float sample2[samples] = {0};

    const float pi = 3.14159265;

    for (int i = 0; i < samples; ++i)
    {
        float a = (float)rand() / RAND_MAX;
        // log(a);
        if (a == 0) a = 1e-8;
        float b = (float)rand() / RAND_MAX;
        // log(b);
        float r = sqrt(-2*log(a));
        float theta = 2*pi*b;
        sample1[i] = r*cos(theta);
        printf("S1: %f\n", sample1[i]);
        sample2[i] = r*sin(theta);
        printf("S2: %f\n", sample2[i]);
    }
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
                    DrawCircle((float)screenWidth/2 + sample1[i] * 300, 500, 20.0f, (Color) {0,0,0,10});
                }
            EndDrawing();
        }
        CloseWindow();
    return 0;
}


/*
This code snippet groups the distribution into bins (classes) and calculates their frequency to plot a histogram
*/


// #include "raylib.h"
// #include <math.h>
// #include <stdlib.h>
// #include <stdio.h>

// #define NUM_SAMPLES 10000
// #define NUM_BINS 500

// int main(int argc, char const *argv[]) {
//     float sample1[NUM_SAMPLES] = {0};

     
//     for (int i = 0; i < NUM_SAMPLES; ++i) {
//         float a = (float)rand() / RAND_MAX;
//         if (a == 0) a = 1e-8;  
//         float b = (float)rand() / RAND_MAX;

//         float r = sqrt(-2 * log(a));
//         float theta = 2 * PI * b;

//         sample1[i] = r * cos(theta);  
//     }

     
//     int frequencies[NUM_BINS] = {0};
//     float minRange = -3.0f;  
//     float maxRange = 3.0f;
//     float binWidth = (maxRange - minRange) / NUM_BINS;

//     for (int i = 0; i < NUM_SAMPLES; ++i) {
//         int binIndex = (int)((sample1[i] - minRange) / binWidth);
//         if (binIndex >= 0 && binIndex < NUM_BINS) {
//             frequencies[binIndex]++;
//         }
//     }
    
//     const int screenWidth = 1920;
//     const int screenHeight = 1000;

//     InitWindow(screenWidth, screenHeight, "Histogram of Gaussian Distribution");
//     SetTargetFPS(60);

     
//     while (!WindowShouldClose()) {
//         BeginDrawing();
//         ClearBackground(RAYWHITE);

         
//         int barWidth = screenWidth / NUM_BINS;  
//         for (int i = 0; i < NUM_BINS; ++i) {
//             int barHeight = frequencies[i] * 10;  
//             DrawRectangle(i * barWidth, screenHeight - barHeight, barWidth - 2, barHeight, DARKBLUE);
//         }

//         EndDrawing();
//     }

     
//     CloseWindow();

//     return 0;
// }
