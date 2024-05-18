#include "GameObjectManager.h"

void GameObjectManager::InitializeGameObjects()
{
	gameObjects.push_back(GameObject(PROGRAMS.GetCompiledPrograms()[0], glm::vec3(0.f, 0.f, -5.f), glm::vec3(0, 1.f, 0), glm::vec3(1.f), MODELS.GetModel(0), Light(0.f, 1.f, 0.f, 1.f), 0));
	gameObjects.push_back(GameObject(PROGRAMS.GetCompiledPrograms()[0], glm::vec3(0.f), glm::vec3(0, 1.f, 0), glm::vec3(1.f), MODELS.GetModel(1), Light(1.f, 1.f, 1.f, 1.f), 1));
}

void GameObjectManager::GameObjectsUpdate()
{
	for (GameObject item : gameObjects)
	{
		item.Update();
		item.Render();
	}
}

