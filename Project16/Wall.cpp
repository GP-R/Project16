#include "Wall.h"

Wall::Wall(const char* shape)
	:GameObject(28, shape)
{
}
Wall::~Wall()
{
}

void Wall::Draw(int y, char* canvas) {
	strncpy(&canvas[y], "бс", strlen("бс"));
}