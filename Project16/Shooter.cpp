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

	static float timeElapsed = 0.0f;            //�帥 �ð�
	static unsigned long lastTime = timeGetTime();   //������ �ð�(temp����)
	unsigned long curTime = timeGetTime();      //���� �ð�
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1�������� �帥 �ð�) 1�ʴ����� �ٲ��ش�.
	timeElapsed += timeDelta;

	while (timeElapsed >= 1.0f)
	{
		bullet->isFired = true;
		bullet->pos = shooter_pos;

		timeElapsed = 0.0f;
	}
	lastTime = curTime;
}*/
