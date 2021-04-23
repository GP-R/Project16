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
	strncpy(&canvas[y], "○", strlen("○"));
	srand((unsigned int)time(NULL));

	static float timeElapsed = 0.0f;            //흐른 시간 static 변수 -> 누적됨
	static unsigned long lastTime = timeGetTime();   //마지막 시간(temp변수)
	unsigned long curTime = timeGetTime();      //현재 시간
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1번생성후 흐른 시간) 1초단위로 바꿔준다.
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