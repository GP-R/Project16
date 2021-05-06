#define _CRT_SECURE_NO_WARNINGS
#include "UI.h"
#include "Screen.h"
int UI::currentCursor = 0;

UI::UI(Screen& screen, const char* prefix, int pos, int sz)
	:GameObject(screen, pos, prefix), sz(sz), data((char*)malloc(strlen(prefix) + sz + 1))
{}

UI::~UI()
{
	free(data);
}
void UI::setData(int value)
{
	static char buf[100];
	sprintf(buf, "%s%d", getShape(), value);
	strncpy(data, buf, length());
}

void UI::draw()
{
	if (isInsideCursor() == false)
	{
		getScreen().draw(data, getPos());
		return;
	}
	if (count % 2)
	{
		getScreen().draw(data, getPos());
	}

}

void UI::process_input(int key)
{
	switch (key)
	{
	case 'a': 
		moveLeft(); 
		break;
	case 'd': 
		moveRight(); 
		break;
	}
}

void UI::moveLeft()
{
	if (isInsideCursor() == false) return;

	GameObject** gos = GameObject::getGameObjects();
	int capacity = GameObject::getMaxGameObject();
	int myPos = getPos();
	int closest = getScreen().length();
	for (int i = 0; i < capacity; i++)
	{
		if (gos[i] == nullptr && gos[i] == this) continue;
		UI* ui = dynamic_cast<UI*>(gos[i]);
		if (ui == nullptr) continue;
		int dist = myPos - ui->getPos();
		if (dist < 0) continue;
		if (dist < closest) closest = dist;
	}
	if (closest == getScreen().length()) return;
	currentCursor = myPos - closest;
}

void UI::moveRight()
{
	if (isInsideCursor() == false) return;

	GameObject** gos = GameObject::getGameObjects();
	int capacity = GameObject::getMaxGameObject();
	int myPos = getPos();
	int closest = getScreen().length();
	for (int i = 0; i < capacity; i++)
	{
		if (gos[i] == nullptr && gos[i] == this) continue;
		UI* ui = dynamic_cast<UI*>(gos[i]);
		if (ui == nullptr) continue;
		int dist = myPos - ui->getPos();
		if (dist < 0) continue;
		if (dist < closest) closest = dist;
	}
	if (closest == getScreen().length()) return;
	currentCursor = myPos - closest;
}

void UI::update()
{
	if (isInsideCursor() == false) return;

	count++;
}