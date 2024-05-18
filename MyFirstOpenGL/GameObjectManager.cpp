#include "GameObjectManager.h"

void GameObjectManager::InitializeGameObjects()
{
	gameObjects.push_back(GameObject(PROGRAMS.GetCompiledPrograms()[0], glm::vec3(0.f, 0.f, -2.f), glm::vec3(0.f, 1.f, 0.f), glm::vec3(1.f), MODELS.GetModel(0), Light(1.f, 1.f, 1.f, 1.f), 0)); //Troll Normal
	gameObjects.push_back(GameObject(PROGRAMS.GetCompiledPrograms()[0], glm::vec3(2.f, 0.f, 0.f), glm::vec3(0.f, 270, 0.f), glm::vec3(1.f), MODELS.GetModel(0), Light(0.322f, 0.525f, 1.f, 1.f), 0)); //Troll Azul
	gameObjects.push_back(GameObject(PROGRAMS.GetCompiledPrograms()[0], glm::vec3(-2.f, 0.f, 0.f), glm::vec3(0.f, 90.f, 0.f), glm::vec3(1.f), MODELS.GetModel(0), Light(0.349f, 1.f, 0.263f, 1.f), 0)); //Troll Verde
	gameObjects.push_back(GameObject(PROGRAMS.GetCompiledPrograms()[0], glm::vec3(0.5f, 0.f, 0.5f), glm::vec3(0.f, 45.f, 0.f), glm::vec3(0.7f, 0.4f, 0.7f), MODELS.GetModel(1), Light(1.f, 1.f, 1.f, 1.f), 1));//Piedra
	gameObjects.push_back(GameObject(PROGRAMS.GetCompiledPrograms()[0], glm::vec3(0.5f, 0.f, -0.5f), glm::vec3(0.f, 135.f, 0.f), glm::vec3(0.7f, 0.4f, 0.7f), MODELS.GetModel(1), Light(1.f, 1.f, 1.f, 1.f), 1));//Piedra
	gameObjects.push_back(GameObject(PROGRAMS.GetCompiledPrograms()[0], glm::vec3(-0.5f, 0.f, -0.5f), glm::vec3(0.f, 45.f, 0.f), glm::vec3(0.7f, 0.4f, 0.7f), MODELS.GetModel(1), Light(1.f, 1.f, 1.f, 1.f), 1));//Piedra
	gameObjects.push_back(GameObject(PROGRAMS.GetCompiledPrograms()[0], glm::vec3(-0.5f, 0.f, 0.5f), glm::vec3(0.f, 135.f, 0.f), glm::vec3(0.7f, 0.4f, 0.7f), MODELS.GetModel(1), Light(1.f, 1.f, 1.f, 1.f), 1));//Piedra

	gameObjects.push_back(GameObject(PROGRAMS.GetCompiledPrograms()[0], glm::vec3(1.f, 4.f, -2.f), glm::vec3(0.f, 1.f, 0.f), glm::vec3(1.f, 0.5f, 1.f), MODELS.GetModel(1), Light(1.f, 1.f, 1.f, 2.5f), 1));//Nube
	gameObjects.push_back(GameObject(PROGRAMS.GetCompiledPrograms()[0], glm::vec3(-2.f, 4.f, 1.f), glm::vec3(0.f, 1.f, 0.f), glm::vec3(1.f, 0.5f, 1.f), MODELS.GetModel(1), Light(1.f, 1.f, 1.f, 2.5f), 1));//Nube

}

void GameObjectManager::GameObjectsUpdate()
{
	for (GameObject item : gameObjects)
	{
		item.Update();
		item.Render();
	}
}

