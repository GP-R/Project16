#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

#include"GameObject.h"
#include"UI.h"
#include"Screen.h"
int main()
{
	Screen screen{ 80 };

	UI* uiPeaShooter = new UI{ screen, "*", 0, 2 + 1 };
	UI* uiSun = new UI{ screen, "@", uiPeaShooter->getEndpoint(), 2 + 1 };
	UI* uiPotatoMine = new UI{ screen, "♣", uiSun->getEndpoint(), 2 + 1 };
	UI* uiWallnut = new UI{ screen, "▒", uiPotatoMine->getEndpoint(), 2 + 1 };

	bool requestExit = false;
	while(requestExit == false)
	{
		screen.clear();

		GameObject** gos = GameObject::getGameObjects();
		int capacity = GameObject::getMaxGameObject();

		bool pressKey = false;
		if (_kbhit())
		{
			int key = _getch();
			if (key == 'x')
				break;
			else if (key == 'n')
			{
				pressKey = true;
				for (int i = 0; i < capacity; i++)
				{
					if (gos[i] == nullptr) continue;
					UI* ui = dynamic_cast<UI*>(gos[i]);
					if (ui == nullptr) continue;
					if (ui->isInsideCursor() == true && pressKey == true)
					{
						ui->moveRight();
						pressKey = false;
					}
				}
			}
			else {
				for (int i = 0; i < capacity; i++)
				{
					if (gos[i] == nullptr) continue;
					gos[i]->process_input(key);
				}
			}
		}
		uiPeaShooter
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