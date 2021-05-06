#include "Shooter.h"
#include "GameObject.h"
Shooter::~Shooter()
{
}

/*void Shooter::Draw(int y, char* canvas) {
	strncpy(&canvas[y], "->", strlen("->"));


}*/
/*void Shooter::fire(int shooter_pos, Bullet* bullet)
{
	if (bullet == nullptr) return;

	static float timeElapsed = 0.0f;            //흐른 시간
	static unsigned long lastTime = timeGetTime();   //마지막 시간(temp변수)
	unsigned long curTime = timeGetTime();      //현재 시간
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1번생성후 흐른 시간) 1초단위로 바꿔준다.
	timeElapsed += timeDelta;

	while (timeElapsed >= 1.0f)
	{
		bullet->isFired = true;
		bullet->pos = shooter_pos;

		timeElapsed = 0.0f;
	}
	lastTime = curTime;
}*/
