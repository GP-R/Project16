#pragma once
#include"GameObject.h"

class Player : public GameObject
{
	char* data;
	int sz;
	static int currentCursor;
	int count;
public:
	Player(Screen& screen, const char* shape, int pos, int sz);
	~Player();
	int length() const { return strlen(getShape()) + sz; }
	int getEndpoint() const { return getPos() + length(); }
	bool isInsideCursor() const { return getPos() <= currentCursor && currentCursor < getEndpoint(); }
	void setData();
	void setData(int value);
	void draw();
	void process_input(int key);
	void moveLeft();
	void moveRight();
	void update();
	void setPlants();
};