#pragma once
class Player;
class ProjectileList;
class EnemiesList;
class StaticList;
class LevelStateHandler
{
private:
	ProjectileList* projetiles;
	EnemiesList* enemies;
	StaticList* statics;
	Player* p1;
	Player* p2;
	int leveltype;
public:
	LevelStateHandler();
	void save();
	void setP1(Player* p1) { this->p1 = p1; }
	void setP2(Player* p2) { this->p2 = p2; }
	void setProjectiles(ProjectileList* projectiles) { this->projetiles = projectiles; }
	void setEnemies(EnemiesList* enemies) { this->enemies = enemies; }
	void setStatics(StaticList* statics) { this->statics = statics; }
	void setType(const int leveltype) { this->leveltype = leveltype; }
};

