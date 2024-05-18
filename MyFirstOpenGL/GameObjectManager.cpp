#include "GameObjectManager.h"

void GameObjectManager::GameObjectsUpdate()
{
	for (GameObject item : gameObjects)
	{
		item.Update();
		item.Render();
	}
}

