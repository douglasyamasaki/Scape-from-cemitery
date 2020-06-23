#pragma once
#include "Level.h"
class SecondLevel : public Level
{
<<<<<<< HEAD
private:
	Warlock* bossref;
	void resetlists();
	bool spawnBoss;
public:
	SecondLevel();
	~SecondLevel(){}
	void getBoss();
	void setSpawn(const bool opt) { spawnBoss = opt; }
	void check_collision();
	void load_static();
	void load_default();
	void update(float deltat);
	void setFinished();
=======
	
>>>>>>> parent of f7c28ad... Updating
};

