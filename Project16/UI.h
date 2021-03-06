#pragma once
#include"GameObject.h"

class Screen;
class UI : public GameObject
{
	char* data;
	int sz;
	static int currentCursor;
	int count;
	bool fixUI;
	bool isBuy;
public:
	UI(Screen& screen, const char* prefix, int pos, int sz, bool fixUI);
	~UI();
	int length() const { return strlen(getShape()) + sz; }
	int getEndpoint() const { return getPos() + length(); }
	bool getBuy() const { return isBuy; }
	void setBuy(bool buy) { isBuy = buy; }
	bool isInsideCursor() const { return getPos() <= currentCursor && currentCursor < getEndpoint(); }
	void setData();
	void setData(int value);
	void draw();
	void process_input(int key);
	void moveLeft();
	void moveRight();
	void update();
	void buyPlants();
};