#include<iostream>

#include"GameObject.h"
#include"Screen.h"
#include "Player.h"
#include "UI.h"
int Player::currentCursor = 22;

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

void Player::setPlants()
{
	GameObject** gos = GameObject::getGameObjects();
	int capacity = GameObject::getMaxGameObject();
	for (int i = 0; i < capacity; i++)
	{
		if (gos[i] == nullptr || gos[i] == this) continue;
		UI* ui = dynamic_cast<UI*>(gos[i]);
		if (ui== nullptr || ui->getBuy() == false) continue;
		{
			for (int j = 0; j < capacity; j++)
			{
				if (gos[j] == nullptr || gos[j] == this) continue;
				Player* player = dynamic_cast<Player*>(gos[j]);
				if (player == nullptr) continue;
				if (player->isInsideCursor() == true)
				{
					player->setShape(ui->getShape());
					ui->setBuy(false);
				}
			}
		}
	}
}


void Player::setData(int value)
{
	if (isInsideCursor() == false) return;
	static char buf[100];
	GameObject** gos = GameObject::getGameObjects();
	int capacity = GameObject::getMaxGameObject();
	for (int i = 0; i < capacity; i++)
	{
		if (gos[i] == nullptr || gos[i] == this) continue;
		UI* ui = dynamic_cast<UI*>(gos[i]);
		if (ui == nullptr) continue;
		if (ui->isInsideCursor() == true)
		{
			sprintf(buf, "%s", ui->getShape());
			strncpy(data, buf, length());
			return;
		}
	}
	sprintf(buf, "%s", getShape());
	strncpy(data, buf, length());
	return;
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
	case 75: // Diretion Left
		moveLeft();
		break;
	case 77: // Diretion Right
		moveRight();
		break;
	case 32: // space bar
		setPlants();
	}
}

void Player::moveLeft()
{
	if (isInsideCursor() == false) return; // 8���� �׸� ������� �˻���

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
