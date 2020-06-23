#pragma once

#include "LevelFactory.h"
#include "PlataformList.h"
#include "Warlock.h"
#include "EnemiesList.h"

class BossFactory: public LevelFactory
{
private:
	void instancePlayers();
	void instanceEnemies();
	void instanceObstacle();


	EnemieList* enemie;
	ObstacleList* obstacles;

public:
	CemetaryFactory(Principal* game = NULL);
	~CemetaryFactory();


	Level* create();
};

