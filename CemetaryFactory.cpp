#include "CemetaryFactory.h"

void CemetaryFactory::instancePlayers()
{
	p1.getHit().getPosition(0, 0);
	p2.getHit().getPosition(0, 0);
}

void CemetaryFactory::instanceEnemies(PlataformList* plat)
{
	nGhost = (rand() % 10) + 5;
	nDragon = (rand() % 10) + 5;

	for (int i = 0; i < nGhost; i++) {
		ghost = new Ghost;
		enemies.setProx(ghost);
		enemies.atual.pos.x = (rand() % 3000) + 100;
		enemies.atual.pos.y = (rand() % 910) ;
	}
	for (i = 0; i < nDragon; i++) {
		dragon = new Dragon;
		enemies.setProx(dragon);
		enemies.atual.pos.x = (rand() % 3000) + 200;
		enemies.atual.pos.y = 850;
	}
}

void CemetaryFactory::instanceObstacle(Palataform* plat)
{
	nSpike = (rand() % 10) + 5;
	nTombstone = (rand() % 10) + 5;
	

	for (int i = 0; i < nSpike; i++) {
		spike = new Spike;
		obstacles.setProx(spike);
		obstacles.atual.pos.x = (rand() % 3000) + 100;
		obstacles.atual.pos.y = 850;
	}

	for (i = 0; i < nTombstone; i++) {
		tomb = new Tombstone;
		obstacles.setProx(tomb);
		obstacles.atual.pos.x = (rand() % 3000) + 20;
		obstacles.atual.pos.y = 850;

	}
}

CemetaryFactory::CemetaryFactory(Principal* game)
{
	Principal* pGame;
}

Level* CemetaryFactory::create()
{	
	Level* level = new Level;

	instanceEnemies();
	instancePlayers();
	instanceObstacle();

	return level;
}
