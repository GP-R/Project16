#include"Screen.h"

void Screen::clear()
{
	memset(canvas, ' ', len - 1);
	canvas[len - 1] = '\0';
}

void Screen::render()
{
	printf("%s\r", canvas);
}

void Screen::draw(const char* shape, int pos)
{
	strncpy(&canvas[pos], shape, strlen(shape));
}

void Screen::draw(int num, int pos)
{
	char buf[10];
	sprintf(buf, "%d", num);
	strncpy(&canvas[pos], buf, strlen(buf));
}