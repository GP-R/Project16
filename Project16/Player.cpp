#include<iostream>

#include"GameObject.h"
#include"Screen.h"
#include "Player.h"

int Player::currentCursor = 20;

Player::Player(Screen& screen, const char* shape, int pos, int sz)
	:GameObject(screen, pos, shape), sz(sz), data((char*)malloc(strlen(shape) + sz + 1))
{}

Player::~Player()
{
	free(data);
}

void Player::setData()
{
	static char buf[100];
	sprintf(buf, "%s", getShape());
	strncpy(data, buf, length());
}

void Player::draw()
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


void Player::process_input(int key)
{
	switch (key)
	{
	case 75:
		moveLeft();
		break;
	case 77:
		moveRight();
		break;
	}
}

void Player::moveLeft()
{
	if (isInsideCursor() == false) return; //t -> b -> ab -> e ������ ���� ���� currentCursor 30��ó�� �ִ°��� this����

	GameObject** gos = GameObject::getGameObjects();
	int capacity = GameObject::getMaxGameObject();
	int myPos = getPos();
	int closest = getScreen().length(); //80
	for (int i = 0; i < capacity; i++)
	{
		if (gos[i] == nullptr || gos[i] == this) continue;
		Player* player = dynamic_cast<Player *>(gos[i]);
		if (player == nullptr) continue;
		int dist = myPos - player->getPos(); //20 - 0 , 20 -7, 20 - 13
		if (dist < 0) continue; // gos���� ������ ui�� �������� �ڽź��� �����ʿ� ������ continue
		if (dist < closest) { // 80 < 20
			closest = dist; //
		}
	}
	if (closest == getScreen().length()) return;
	currentCursor = myPos - closest;
}

void Player::moveRight()
{
	if (isInsideCursor() == false) return; //�ڱ��ڽ��� �˻��ϰ� ������ �ٵ� �״����͵� �˻��ϰ� �����ΰ�
	GameObject** gos = GameObject::getGameObjects();
	int capacity = GameObject::getMaxGameObject();
	int myPos = getPos();// b: 0 pos 7
	int closest = getScreen().length(); //80
	for (int i = capacity - 1; i >= 0; i--)
	{
		if (gos[i] == nullptr || gos[i] == this) continue;
		Player* player = dynamic_cast<Player *>(gos[i]);//Player ui1 ui2 ui3 ui4 ui ab
		if (player == nullptr) continue;
		int dist = player->getPos() - myPos; //-6     -7 dist 6
		if (dist < 0) continue; //�ڽź��� ���ʿ��ִ� ui�� �Ѱܹ�����
		if (dist < closest) { // 80 < 20 dist�� ����
			closest = dist; // closest = -6 .. -12
		}
	}
	if (closest == getScreen().length()) return;
	currentCursor = myPos + closest;
}

void Player::update()
{
	if (isInsideCursor() == false) return;

	count++;
}