#include "Sun.h"

Sun::Sun(const char* shape)
	:GameObject(0, shape)
{
	sun_energy = false;
	energy_pos = -1;
}
Sun::~Sun()
{
}

void Sun::Draw(int y, char* canvas) {
	strncpy(&canvas[y], "��", strlen("��"));
	srand((unsigned int)time(NULL));

	static float timeElapsed = 0.0f;            //�帥 �ð� static ���� -> ������
	static unsigned long lastTime = timeGetTime();   //������ �ð�(temp����)
	unsigned long curTime = timeGetTime();      //���� �ð�
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1�������� �帥 �ð�) 1�ʴ����� �ٲ��ش�.
	timeElapsed += timeDelta;

	int RandNum = (rand() % 5) + 1;
	int Randpos = 2 * (rand() % 4);//0,2,4,6
	while (timeElapsed >= RandNum)
	{
		if (y - Randpos >= 40 && y + Randpos <= 56)
		{
			sun_energy = true;
			
			energy_pos = y + Randpos;
		}
		timeElapsed = 0.0f;
	}
	lastTime = curTime;
}

void Sun::Energy(char* canvas) {

}