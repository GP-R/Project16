#pragma once
#include "GameObject.h"

class Mine : public GameObject {
public:
	Mine(const char* shape="��");
	~Mine();

	void Draw(int y, char* canvas);
};