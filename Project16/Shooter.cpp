#include "Shooter.h"
#include "GameObject.h"
Shooter::Shooter(const char* shape)
	:GameObject(-1, shape)
{
}
Shooter::~Shooter()
{
}

void Shooter::Draw(int y, char* canvas) {
	Field_Exist = true;
	strncpy(&canvas[y], "->", strlen("->"));


}
void Shooter::fire(int shooter_pos, Bullet* bullet)
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
}

Bullet::Bullet(const char* shape)
	:GameObject(-1, shape), isFired(false), pos(-1)
{

}

Bullet::~Bullet() {};

bool Bullet::isInside(int length)
{
	return pos <= (length - strlen(shape));
}

void Bullet::update(int enemy_pos)
{
	if (isFired == false) return;

	pos++;
	if (enemy_pos <= pos)
	{
		isFired = false;
	}
}

void Bullet::draw(char* canvas, int maxCount)
{
	if (isFired == false) return;
	if (isInside(maxCount) == false) return;
	strncpy(&canvas[pos], shape, strlen(shape));
}