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
	bool finished;
	bool lost;

public:
	Level() { p1 = nullptr; p2 = nullptr; p2 = false; finished = false; lost = false; }
	virtual void check_collision() = 0;
	virtual void load_default() = 0;
	virtual void update(float deltat) = 0;
	virtual void load_static() = 0;
	sf::RectangleShape getCenter();
	void draw(sf::RenderWindow* window);
	void setP1ref(Player* p1) { this->p1 = p1; }
	void setP2ref(Player* p2) { this->p2 = p2; }
	Player* getP1ref() { return p1; }
	Player* getP2ref() { return p2; }
	const bool getFinished() const { return finished; }
	const bool getLost() const { return lost; }
	void setLost();
	void savePoints();
	virtual void setFinished() = 0;
};