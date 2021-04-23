#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
class GameObject {
public:

	int pos;
	char shape[100];
	int cost;
	bool Field_Exist;
	GameObject(int pos= -1, const char* shape="");
	~GameObject();

	void setShape(const char* shape);
	void draw(char* canvas, int maxCount);
	void All_UI_Draw(char* canvas);
	void Cost_Draw(char* canvas, char* cost);
	void Game_Map_Draw(char*canvas);
	void UI_Draw(char* canvas);
	virtual void Draw(int y, char *canvas);
};