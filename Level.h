#pragma once
#include "StaticList.h"
#include "EnemiesList.h"
#include "ProjectileList.h"
#include "Collisor.h"
class Player;
class Level {
protected:
	StaticList platforms;
	EnemiesList enemies;
	ProjectileList projectiles;
	Collisor collider;
	Player* p1;
	Player* p2;
	bool pl2;

public:
	Level() { p1 = nullptr; p2 = nullptr; p2 = false; }
	virtual void check_collision() = 0;
	virtual void load_default() = 0;
	virtual void update(float deltat) = 0;
	virtual void load_static() = 0;
	void draw(sf::RenderWindow* window);
	void setP2() { pl2 = true; }
	Player* getP1ref() { return p1; }
	Player* getP2ref() { return p2; }
};