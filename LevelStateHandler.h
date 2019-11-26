#pragma once
class Player;
class ProjectileList;
class EnemiesList;
class ObstacleList;
class LevelStateHandler
{
private:
	ProjectileList* projectiles;
	EnemiesList* enemies;
	ObstacleList* obstacles;
	int waitedproj;
	int waitedobjeticles;
	int waitedenemies;
	int ghostquantity;
	bool hasSpawned;
	Player* p1;
	Player* p2;
	int leveltype;
	int pls;
	enum class SaveType;
public:
	LevelStateHandler();
	void save();
	void setP1(Player* p1) { this->p1 = p1; }
	void setP2(Player* p2) { this->p2 = p2; }
	void load();
	void setHasSpawned(const bool opt) { this->hasSpawned = opt; }
	void setGhostQuantity(const int valor) { ghostquantity = valor; }
	void setList(ProjectileList* projectiles) { this->projectiles = projectiles; }
	void setList(EnemiesList* enemies) { this->enemies = enemies; }
	void setList(ObstacleList* obstacles) { this->obstacles = obstacles; }
	void setType(const int leveltype) { this->leveltype = leveltype; }
	void setwProj(const int value) { waitedproj = value; }
	void setwEnemies(const int value) { waitedenemies = value; }
	void setwObj(const int value) { waitedobjeticles = value; }
};

