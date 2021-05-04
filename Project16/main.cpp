#include"GameObject.h"
#define maxSetCount 9
int main()
{
	const int maxCount = 100;
	char canvas[maxCount+1];//0~100
	Sun sun[maxSetCount];
	Shooter Pearshooter[10];
	Mine Potato_Mine[10];
	Wall Wallnut[10];
	GameObject Map;
	GameObject Cost;
	GameObject *make[100];
	Bullet bullet[10];
	
	for (int i = 0; i < 100; i++)
	{
		make[i] = new GameObject;
	}
	char cost_save[maxCount];
	int map_pos = 40;
	
	int x = 0;
	int y = 1;
	int z[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int zNum = 0;
	int PaintNum = 0;
	int framecount[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	while (true)
	{
		clear(canvas, maxCount);
		Map.All_UI_Draw(canvas);
		sprintf(cost_save, "%d", Cost.cost);
		Map.Cost_Draw(canvas, cost_save);
		Map.Game_Map_Draw(canvas);

		if (_kbhit())
		{
			int key = _getch();
			switch (key)
			{
			case 'a':
				if(x>0)
					x -= 6;
				break;
			case 'd':
				if(x <18)
					x += 6;
				break;
			case ' ':
				if (x == 0 && Cost.cost >= 50) {
					Cost.cost -= 50;
					make[PaintNum] = &sun[PaintNum];
					sun[PaintNum].Field_Exist = true;
					PaintNum++;
				}
				if (x == 6 && Cost.cost >= 100) {
					Cost.cost -= 100;
					make[PaintNum] = &Pearshooter[PaintNum];
					PaintNum++;
				}
				if (x == 12 && Cost.cost >= 25) {
					Cost.cost -= 25;
					make[PaintNum] = &Potato_Mine[PaintNum];
					PaintNum++;
				}
				if (x == 18 && Cost.cost >= 50) {
					Cost.cost -= 50;
					make[PaintNum] = &Wallnut[PaintNum];
					PaintNum++;
				}
			case 75:
				if (y > 1)
					y -= 1;
				break;
			case 77:
				if (y < 9)
					y += 1;
				break;
			case 13:
				z[zNum] = y;
				zNum++;
				break;
			case 's':
				for (int i = 0; i < 10; i++)
				{
					if (sun[i].sun_energy == true)
					{
						sun[i].sun_energy = false;
						Cost.cost += 25;
					}
				}
			default:
				break;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			make[i]->Draw(38 + z[i] * 2, canvas);
		}
		for (int i = 0; i < 10; i++)
		{
			if (sun[i].sun_energy == true)
				strncpy(&canvas[sun[i].energy_pos], "◎", strlen("◎"));
		}
		for (int i = 0; i < 10;i++)
		{
			if (Pearshooter[i].Field_Exist == true) {
				if (bullet[i].isFired == false)
				{
					Pearshooter[i].fire(y, &bullet[i]);
				}
			}
		}
		for (int i = 0; i < 10; i++)
			bullet[i].update(80);
		for (int i = 0; i < 10; i++)
		{
			if (bullet[i].isFired == false) continue;
			bullet[i].draw(canvas, 100);
		}
		Map.UI_Draw(canvas);
		strncpy(&canvas[38], "  ", strlen("  "));
		if (x == 0 && framecount[0] % 2 == 1)
			strncpy(&canvas[8], "      ", strlen("      "));
		if (x == 6 && framecount[1] % 2 == 1)
			strncpy(&canvas[15], "       ", strlen("       "));
		if (x == 12 && framecount[2] % 2 == 1)
			strncpy(&canvas[23], "      ", strlen("      "));
		if (x == 18 && framecount[3] % 2 == 1) 
			strncpy(&canvas[30], "      ", strlen("      "));
	
		for (int i = 1; i < 10; i++)
			if(y==i&&framecount[3+i] %2 == 1)
				strncpy(&canvas[38+(2*i)], "  ", strlen("  "));
		
		render(canvas, maxCount);

		for(int i = 0 ; i < 13; i++)
			framecount[i]++;
	}

	for (int i = 0; i < 100; i++)
	{
		delete make[i];
		make[i] = NULL;
	}
	printf("정상적으로 종료되었습니다");
	return 0;
}

void clear(char* canvas, int length)
{
	memset(canvas, ' ', length);
	canvas[length] = '\0';
}

void render(const char* canvas, int lastPosition)
{
	printf("%s\r", canvas);
}