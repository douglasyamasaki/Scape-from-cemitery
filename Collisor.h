#pragma once
#pragma once
#include <SFML/Graphics.hpp>

class ProjectileList;
class EnemiesList;
class StaticList;
class ObstacleList;
class Body;
class Player;
class Collisor
{
private:
	ProjectileList* projectiles;
	EnemiesList* enemies;
	StaticList* statics;
	ObstacleList* obstacles;
	Player* p1r;
	Player* p2r;
	bool CheckCollision(Body* thisbody, Body* other, sf::Vector2f& direction, float push);
public:
	Collisor();
	~Collisor() {}
	void CollidePlayerObstacle();
	void CollidePlayerPlatform();
	void CollidePlayerEnemie();
	void CollideEnemiePlatform();
	void CollideProjectilePlatform();
	void CollideProjectilePlayer();
	void CollideProjectileEnemie();
	void setObstacleList(ObstacleList* ref) { obstacles = ref; }
	void setProjectileList(ProjectileList* ref) { projectiles = ref; }
	void setEnemiesList(EnemiesList* ref) { enemies = ref; }
	void setStaticList(StaticList* ref) { statics = ref; }
	void setP1r(Player* ref) { p1r = ref; }
	void setP2r(Player* ref) { p2r = ref; }
};

