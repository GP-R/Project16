#include "Wall.h"

Wall::~Wall()
{
}

void Wall::Draw(int y, char* canvas) {
	strncpy(&canvas[y], "бс", strlen("бс"));
}