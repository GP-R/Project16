#pragma once
#include "GameObject.h"

class Mine : public GameObject {
public:
	Mine(const char* shape="¢Á");
	~Mine();

	void Draw(int y, char* canvas);
};