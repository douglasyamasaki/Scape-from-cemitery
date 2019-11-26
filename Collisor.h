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
	void setList(ObstacleList* ref) { obstacles = ref; }
	void setList(ProjectileList* ref) { projectiles = ref; }
	void setList(EnemiesList* ref) { enemies = ref; }
	void setList(StaticList* ref) { statics = ref; }
	void setP1r(Player* ref) { p1r = ref; }
	void setP2r(Player* ref) { p2r = ref; }
};

