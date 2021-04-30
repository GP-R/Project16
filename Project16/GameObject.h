#pragma once
#include<iostream>
#include<conio.h>
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<ctime>
#include<Windows.h>
#include<time.h>
class GameObjectManager;
class Screen;
class GameObject {
	int pos;
	char* shape;
	Screen& screen;
	static GameObjectManager gameObjectManager;
public:
	GameObject(Screen& screen, int pos, const char* shape);
	~GameObject();
	const char* getShape() { return shape; }
	int getPos() { return pos; }
	Screen& getScreen() { return screen; }

	GameObject** getGameObjects();
	int getMaxGameObject();
	void setShape(const char* shape);
	void draw(char* canvas, int maxCount);
	void All_UI_Draw(char* canvas);
	void Cost_Draw(char* canvas, char* cost);
	void Game_Map_Draw(char*canvas);
	void UI_Draw(char* canvas);
	virtual void Draw(int y, char *canvas);
};