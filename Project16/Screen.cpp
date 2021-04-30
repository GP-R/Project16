#include"Screen.h"

void Screen::clear()
{
	memset(canvas, ' ', len - 1);
}

void Screen::render()
{
	printf("%s\r", canvas);
}

void Screen::draw(const char* shape, int pos)
{
	strncpy(&canvas[pos], shape, strlen(shape));
}