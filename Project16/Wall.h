#pragma once
#include "GameObject.h"

class Wall : public GameObject {
public:
	Wall(const char* shape="��");
	~Wall();
	void Draw(int y, char* canvas);
};