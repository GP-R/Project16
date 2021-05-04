#pragma once
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
	virtual ~GameObject();

	const char* getShape() const { return shape; }
	int getPos() const { return pos; }
	Screen& getScreen() const { return screen; }

	static GameObject** getGameObjects();
	static int getMaxGameObject();

	void setShape(const char* shape);
	void setPos(int pos) { this->pos = pos; }

	virtual void draw();
	virtual void moveLeft() { --pos; }
	virtual void moveRight() { ++pos; }
};