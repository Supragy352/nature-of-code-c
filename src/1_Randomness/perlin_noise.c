#include <raylib.h>
#include "../../include/stb_perlin.h"

int main(int argc, char const *argv[]) {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Perlin Noise");
    SetTargetFPS(60);

    float scale = 0.03f;
    float z = 0.0f;
    int type = 1;
    int octave = 1;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            if (IsKeyPressed(KEY_R)) {
              if (octave < 8) {
                octave++;
              } else {
                octave = 1;
              }
            }

            if (IsKeyPressed(KEY_T)) {
                if (type < 6) {
                    type++;
                } else {
                    type = 1;
                }
            }
            scale = GetMouseX() / 10000.0f;
            for (int y = 0; y < screenHeight; y++) {
                for (int x = 0; x < screenWidth; x++) {
                    float n;
                    switch (type) {
                        case 1:
                            n = stb_perlin_noise3(x * scale, y * scale, z, 0,0,0);
                        break;
                        case 2:
                            n = stb_perlin_noise3_seed(x * scale, y * scale, z, 0,0,0, 1234);
                        break;
                        case 3:
                            n = stb_perlin_ridge_noise3(x * scale, y * scale, z, 2, 0.5, 0, octave);
                        break;
                        case 4:
                            n = stb_perlin_fbm_noise3(x * scale, y * scale, z, 2, 0.5, octave);
                        break;
                        case 5:
                            n = stb_perlin_turbulence_noise3(x * scale, y * scale, z, 2, 0.5, octave);
                        break;
                    }
                    unsigned char c = (unsigned char)((n + 1.0f) * 0.5f * 255);
                    DrawPixel(x, y, (Color){c, c, c, 255});
                }
            }
            z += 0.04f; // animate over time
sl        EndDrawing();
    }
    CloseWindow();
    return 0;
}