#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>

#include"GameObject.h"
#include"GameObjectManager.h"
#include"Screen.h"
#include"UI.h"

GameObjectManager GameObject::gameObjectManager{ 1 };

GameObject** GameObject::getGameObjects() { return gameObjectManager.getGameObjects(); }
int GameObject::getMaxGameObject() { return gameObjectManager.getCapacity(); }

GameObject::GameObject(Screen& screen, int pos, const char* shape) 
	:screen(screen), pos(pos)
{
	setShape(shape);
	gameObjectManager.add(this);
}

GameObject::~GameObject() {
	gameObjectManager.remove(this);
}

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

void GameObject::draw()
{

}