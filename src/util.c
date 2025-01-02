#include "../include/util.h"
#include <raylib.h>
#include <stdlib.h>

Vector2 randomVector2(int min, int max) {
	return (Vector2) {
		.x = (rand() % (max - min + 1)) + min ,
    	.y = (rand() % (max - min + 1)) + min
	};
}
Vector2 randomVector2Full(int minX, int maxX, int minY, int maxY) {
	return (Vector2) {
		.x = (rand() % (maxX - minX + 1)) + minX,
    	.y = (rand() % (maxY - minY + 1)) + minY
	};
}
Vector3 randomVector3(int min, int max) {
	return (Vector3) {
		.x = (rand() % (max - min + 1)) + min,
    	.y = (rand() % (max - min + 1)) + min,
    	.z = (rand() % (max - min + 1)) + min
	};
}
Vector3 randomVector3Full(int minX, int maxX, int minY, int maxY, int minZ, int maxZ){
	return (Vector3) {
		.x = (rand() % (maxX - minX + 1)) + minX,
    	.y = (rand() % (maxY - minY + 1)) + minY,
    	.z = (rand() % (maxZ - minZ + 1)) + minZ
	};
}
Vector4 randomVector4(int min, int max) {
	return (Vector4) {
		.x = (rand() % (max - min + 1)) + min,
		.y = (rand() % (max - min + 1)) + min,
		.z = (rand() % (max - min + 1)) + min,
    	.w = (rand() % (max - min + 1)) + min
	};
}
Vector4 randomVector4Full(int minX, int maxX, int minY, int maxY, int minZ, int maxZ, int minW, int maxW) {
	return (Vector4) {
		.x = (rand() % (maxX - minX + 1)) + minX,
    	.y = (rand() % (maxY - minY + 1)) + minY,
    	.z = (rand() % (maxZ - minZ + 1)) + minZ,
    	.w = (rand() % (maxW - minW + 1)) + minW
	};
}
Color randomColor() {
	return (Color) {
		.r = (rand() % 256),
    	.g = (rand() % 256),
    	.b = (rand() % 256),
    	.a = (rand() % 256)
	};
}
