#pragma once
#include"main.h"
class Screen {
	int len;
	char* canvas;

public:
	Screen(int maxCount = 80)
		:len(maxCount + 1)
	{
		canvas = (char*)malloc(sizeof(char*)*maxCount + 1);
	}

	~Screen()
	{
		free((void*)canvas);
		canvas = nullptr;
		len = 0;
	}

	int length() { return len - 1; }
	void clear();
	void render();
	void draw(const char* shape, int pos);

};