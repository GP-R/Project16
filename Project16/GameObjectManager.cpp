#include"GameObjectManager.h"

void GameObjectManager::add(GameObject* obj)
{
	if (obj == nullptr) return;
	for (int i = 0; i < capacity; i++)
	{
		if (gos[i] != nullptr) continue;
		gos[i] = obj;
		return;
	}
	//gos¹è¿­ÀÌ ²ËÃ¡À»¶§
	gos = (GameObject**)realloc(gos, sizeof(GameObject*) * 2 * capacity);
	//´Ã·ÁÁØ ¹è¿­ ÃÊ±âÈ­
	for (int i = capacity; i < capacity * 2; i++)
	{
		gos[i] = nullptr;
	}
	gos[capacity] = obj;
	capacity *= 2;
}

void GameObjectManager::remove(GameObject* obj)
{
	if (obj == nullptr) return;
	for (int i = 0; i < capacity; i++)
	{
		if (gos[i] == obj)
			gos[i] = nullptr;
		return;
	}
}