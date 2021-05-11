#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

#include"GameObject.h"
#include"UI.h"
#include"Screen.h"
#include"Player.h"
int main()
{
	Screen screen{ 80 };
	int money = 0;
	UI* uiMoney = new UI{ screen, "$", 0 , 4 + 1 ,true};
	UI* uiPeaShooter = new UI{ screen, "*", uiMoney->getEndpoint(), 1 + 1 , false};
	UI* uiSun = new UI{ screen, "@", uiPeaShooter->getEndpoint(), 1+ 1 , false};
	UI* uiPotatoMine = new UI{ screen, "♣", uiSun->getEndpoint(), 1 + 1 , false};
	UI* uiWallnut = new UI{ screen, "■", uiPotatoMine->getEndpoint(), 1 + 1 , false};

	Player* playBox[8];
	for (int i = 0; i < 8; i++)
	{
		playBox[i] = new Player{ screen, "□", uiWallnut->getEndpoint() + (i * 3) , 1 };
	}
	bool requestExit = false;
	while(requestExit == false)
	{
		screen.clear();

		GameObject** gos = GameObject::getGameObjects();
		int capacity = GameObject::getMaxGameObject();

		bool pressDKey = false;
		bool pressRightKey = false;
		if (_kbhit())
		{
			int key = _getch();
			if (key == 'x')
				break;
			else if (key == 'd')
			{
				pressDKey = true;
				for (int i = 0; i < capacity; i++)
				{
					if (gos[i] == nullptr) continue;
					UI* ui = dynamic_cast<UI*>(gos[i]);
					if (ui == nullptr) continue;
					if (ui->isInsideCursor() == true && pressDKey == true)
					{
						ui->moveRight();
						pressDKey = false;
					}
				}
			}
			else if (key == 77)
			{
				pressRightKey = true;
				for (int i = 0; i < capacity; i++)
				{
					if (gos[i] == nullptr) continue;
					Player* player = dynamic_cast<Player*>(gos[i]);
					if (player == nullptr) continue;
					if (player->isInsideCursor() == true && pressRightKey == true)
					{
						player->moveRight();
						pressRightKey = false;
					}
				}
			}
			else if (key == 'm')
			{
				money += 50;
			}
			else {
				for (int i = 0; i < capacity; i++)
				{
					if (gos[i] == nullptr) continue;
					gos[i]->process_input(key);
				}
			}
		}
		uiMoney->setData(money);
		uiPeaShooter->setData();
		uiSun->setData();
		uiPotatoMine->setData();
		uiWallnut->setData();
		for (int i = 0; i < 8; i++)
		{
			playBox[i]->setData();
		}
		gos = GameObject::getGameObjects();
		capacity = GameObject::getMaxGameObject();
		for (int i = 0; i < capacity; i++)
		{
			if (gos[i] == nullptr) continue;
			gos[i]->update();
		}


		for (int i = 0; i < capacity; i++)
		{
			if (gos[i] == nullptr) continue;
			gos[i]->draw();
		}
		screen.render();
		Sleep(100);
	}
	printf("정상적으로 종료되었습니다");
	return 0;
}