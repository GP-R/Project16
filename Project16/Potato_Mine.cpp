#include "Potato_Mine.h"
#include "GameObject.h"

Mine::~Mine()
{
}

void Mine::Draw(int y , char* canvas) {
	strncpy(&canvas[y], "¢Á", strlen("¢Á"));
}