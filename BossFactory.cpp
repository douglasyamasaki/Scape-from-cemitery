#include "BossFactory.h"

void BossFactory::instancePlayers()
{
	p1.getHit().getPosition(0, 0);
	p2.getHit().getPosition(0, 0);
}

void BossFactory::instanceEnemies()
{
	boss = new Warlock;
	enemie.setProx(boss);
	enemie.atual.pos.x = 2000;
	enemie.atual.pos.y = 850;
}

void BossFactory::instanceObstacle()
{
	nMine = (rand() % 10) + 5;
	nTombstone = (rand() % 10) + 5;
	for (i = 0; i < nMine; i++) {
		mine = new Mine
			obstacles.setProx(mine);
		obstacles.atual.pos.x = (rand() % 3000) + 200;
		obstacles.atual.pos.y = 850;
	}
	for (i = 0; i < nTombstone; i++) {
		tomb = new Tombstone;
		obstacles.setProx(tomb);
		obstacles.atual.pos.x = (rand() % 3000) + 20;
		obstacles.atual.pos.y = 850;

	}
}

Level* BossFactory::create()
{
	Level* level = new Level;
	
	instancePlayers();
	instanceEnemies();
	instanceObstacle();

	return level;
}
