#pragma once
#include "GameObject.h"

class Bullet : public GameObject {
public:
	/*Bullet(const char* shape = "**");
	~Bullet();*/
	int pos;
	bool	isFired;
	/*bool isInside(int length);
	void update(int enemy_pos);
	void draw(char* canvas, int maxCount);*/
};

class Shooter : public GameObject {
public:
	//Shooter(const char* shape = ">");
	~Shooter();


	//void Draw(int y, char* canvas);
	//void fire(int shooter_pos, Bullet* bullet);
};