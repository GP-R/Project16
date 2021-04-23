#include"GameObject.h"

GameObject::GameObject(int pos, const char* shape) 
	:pos(pos)
{
	setShape(shape);
	cost = 50;
	Field_Exist = false;
}

GameObject::~GameObject() {}

void GameObject::setShape(const char* shape)
{
	int len = strlen(shape); // len >= 0
	if (len >= 100) {
		// 0 ... 98
		// 99에는 널문자
		strncpy(this->shape, shape, 100 - 1);
		this->shape[100 - 1] = '\0';
	}
	else
		strcpy(this->shape, shape);
}

void GameObject::All_UI_Draw(char* canvas)
{
	strncpy(&canvas[8], "○(50) ->(100) ⊙(25) ■(50)", strlen("○(50) ->(100) ⊙(25) ■(50)"));
}

void GameObject::Cost_Draw(char* canvas, char* cost)
{
	strncpy(&canvas[3], cost, strlen(cost));
}

void GameObject::Game_Map_Draw(char*canvas)
{
	strncpy(&canvas[40], "□□□□□□□□□", strlen("□□□□□□□□□"));
}

void GameObject::UI_Draw(char* canvas) {
	strncpy(&canvas[0], "●", strlen("●"));
}

void GameObject::Draw(int y, char* canvas)
{

}