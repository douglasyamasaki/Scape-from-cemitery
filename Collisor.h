#pragma once
#pragma once
#include <SFML/Graphics.hpp>

class ProjectileList;
class EnemiesList;
class StaticList;
class Body;
class Player;
class Collisor
{
private:
	ProjectileList* projectiles;
	EnemiesList* enemies;
	StaticList* statics;
	Player* p1r;
	Player* p2r;
	bool CheckCollision(Body* thisbody, Body* other, sf::Vector2f& direction, float push);
public:
	Collisor();
	~Collisor() {}
	void CollidePlayerPlatform();
	void CollidePlayerEnemie();
	void CollideEnemiePlatform();
	void CollideProjectilePlatform();
	void CollideProjectilePlayer();
	void CollideProjectileEnemie();

};

