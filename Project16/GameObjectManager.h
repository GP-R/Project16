#pragma once
#include"GameObject.h"

class GameObjectManager {
	int capacity;
	GameObject** gos;

public:
	GameObjectManager(int capacity)
		:capacity(capacity), gos((GameObject**)malloc(sizeof(GameObject*)*capacity))
	{
		for (int i = 0; i < capacity; i++)
		{
			gos[i] = (GameObject*)nullptr;
		}
	}

	~GameObjectManager()
	{
		for (int i = 0; i < capacity; i++)
		{
			if (gos[i] == nullptr) continue;
			delete gos[i];
			gos[i] = (GameObject*)nullptr;
		}
		free(gos);
		gos = (GameObject**)nullptr;
		capacity = 0;
	}

	void add(GameObject* obj);
	void remove(GameObject* obj);

	GameObject** getGameObjects() { return gos; }
	int getCapacity() { return capacity; }
};