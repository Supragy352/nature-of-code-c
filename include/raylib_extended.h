#pragma once
#include <raylib.h>

// ############## DOT STRUCT #################

typedef struct Dot {
	Vector2 pos;
	Vector2 vel;
	int size;
	Color color;
} DOT;

void drawDot(DOT *dot);
void moveDot(DOT *dot, int x, int y);
void moveDotV(DOT *dot, Vector2 dp);
DOT createDot(Vector2 position);