#pragma once
#include "GameObject.h"

class Mine : public GameObject {
public:
	~Mine();

	void Draw(int y, char* canvas);
};