#pragma once
#include"GameObject.h"

class UI : public GameObject
{
	char* data;
	int sz;
	static int currentCursor;
	int count;

public:
	int length() { return strlen(getShape()) + sz; }
};