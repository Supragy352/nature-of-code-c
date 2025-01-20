#pragma once
#include <raylib.h>


int randomIntFromArray(int* a, int size);
float randomFloat(int min, int max);
float randomFloatBtwFloat(float min, float max);
Vector2 randomVector2(int min, int max);
Vector2 randomVector2Full(int minX, int maxX, int minY, int maxY);
Vector3 randomVector3(int min, int max);
Vector3 randomVector3Full(int minX, int maxX, int minY, int maxY,int minZ, int maxZ);
Vector4 randomVector4(int min, int max);
Vector4 randomVector4Full(int minX, int maxX, int minY, int maxY, int minZ, int maxZ, int minW, int maxW);
float randomGaussian(float mean, float sd);
Color randomColor();