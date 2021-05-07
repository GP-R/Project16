#define _CRT_SECURE_NO_WARNINGS
#include "UI.h"
#include "Screen.h"
int UI::currentCursor = 8;

UI::UI(Screen& screen, const char* prefix, int pos, int sz)
	:GameObject(screen, pos, prefix), sz(sz), data((char*)malloc(strlen(prefix) + sz + 1))
{
	moneyUI = false;
}
UI::UI(Screen& screen, int num, int pos, int sz)
	: GameObject(screen, pos, num), sz(sz), data((char*)malloc(sizeof(num) + sz + 1))
{
	moneyUI = true;
}
UI::~UI()
{
	free(data);
}
void UI::setData()
{
	static char buf[100];
	sprintf(buf, "%s", getShape());
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

void UI::draw(int num)
{
	getScreen().draw(num, getPos());
}

void UI::process_input(int key)
{
	if (moneyUI == true) return;
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
	if (moneyUI == true) return;
	if (isInsideCursor() == false) return; //t -> b -> ab -> e ������ ���� ���� currentCursor 30��ó�� �ִ°��� this����

	GameObject** gos = GameObject::getGameObjects();
	int capacity = GameObject::getMaxGameObject();
	int myPos = getPos();
	int closest = getScreen().length(); //80
	for (int i = 0; i < capacity; i++)
	{
		if (gos[i] == nullptr || gos[i] == this) continue;
		UI* ui = dynamic_cast<UI *>(gos[i]);
		if (ui == nullptr || ui->moneyUI == true) continue;
		int dist = myPos - ui->getPos(); //20 - 0 , 20 -7, 20 - 13
		if (dist < 0) continue; // gos���� ������ ui�� �������� �ڽź��� �����ʿ� ������ continue
		if (dist < closest) { // 80 < 20
			closest = dist; //
		}
	}
	if (closest == getScreen().length()) return;
	currentCursor = myPos - closest;
}

void UI::moveRight()
{
	if (moneyUI == true) return;
	if (isInsideCursor() == false) return; //�ڱ��ڽ��� �˻��ϰ� ������ �ٵ� �״����͵� �˻��ϰ� �����ΰ�
	GameObject** gos = GameObject::getGameObjects();
	int capacity = GameObject::getMaxGameObject();
	int myPos = getPos();// b: 0 pos 7
	int closest = getScreen().length(); //80
	for (int i = capacity - 1; i >= 0; i--)
	{
		if (gos[i] == nullptr || gos[i] == this) continue;
		UI* ui = dynamic_cast<UI *>(gos[i]);//Player ui1 ui2 ui3 ui4 ui ab
		if (ui == nullptr || ui->moneyUI == true) continue;
		int dist = ui->getPos() - myPos; //-6     -7 dist 6
		if (dist < 0) continue; //�ڽź��� ���ʿ��ִ� ui�� �Ѱܹ�����
		if (dist < closest) { // 80 < 20 dist�� ����
			closest = dist; // closest = -6 .. -12
		}
	}
	if (closest == getScreen().length()) return;
	currentCursor = myPos + closest;
}

void UI::update()
{
	if (moneyUI == true) return;
	if (isInsideCursor() == false) return;

	count++;
}