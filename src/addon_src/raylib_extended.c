#include "../../include/raylib_extended.h"
#include <raylib.h>

void drawDot(DOT *dot) {
	DrawCircleV(dot->pos, dot->size, dot->color);
}

void moveDot(DOT *dot, int x, int y) {
	dot->pos.x += x;
	dot->pos.y += y;
}

DOT createDot(Vector2 position) {
	return (DOT){
		.pos = position,
		.vel = (Vector2) {0,0},
		.size = 1.0f,
		.color = WHITE
	};
}
void moveDotV(DOT *dot, Vector2 dp) {
		dot->pos.x += dp.x;
		dot->pos.y += dp.y;
}