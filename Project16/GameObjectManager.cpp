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
	//gos�迭�� ��á����
	gos = (GameObject**)realloc(gos, sizeof(GameObject*) * 2 * capacity);
	//�÷��� �迭 �ʱ�ȭ
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