#pragma once
#include "LevelFactory.h"
#include "PlataformList.h"
#include "Ghost.h"
#include "Dragon.h"
#include "EnemiesList.h"
#include "ObstacleList.h"
#include "Mine.h"
#include "Spike.h"
#include "Tombstone.h"
#include <stdlib>


class CemetaryFactory: public LevelFactory
{
private:
	void instancePlayers();
	void instanceEnemies();
	void instanceObstacle();


	EnemieList* enemies;
	ObstacleList* obstacles;

public:
	CemetaryFactory(Principal* game = NULL);
	~CemetaryFactory();


	Level* create();
};

