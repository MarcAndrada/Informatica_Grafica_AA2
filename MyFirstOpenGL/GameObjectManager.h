#pragma once
#include <vector>
#include "GameObject.h"


#define GAME_OBJECTS GameObjectManager::Instance()


class GameObjectManager
{
public:
	inline static GameObjectManager& Instance()
	{
		static GameObjectManager manager;
		return manager;
	}

	std::vector<GameObject> gameObjects;

	void GameObjectsUpdate();

private:
	GameObjectManager() = default;
	GameObjectManager(const GameObjectManager&) = delete;
	GameObjectManager& operator =(const GameObjectManager&) = delete;
};

