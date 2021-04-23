#pragma once
#include "GameObject.h"

class Wall : public GameObject {
public:
	Wall(const char* shape="бс");
	~Wall();
	void Draw(int y, char* canvas);
};