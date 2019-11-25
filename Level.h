#pragma once
#include "StaticList.h"
#include "EnemiesList.h"
#include "ProjectileList.h"
#include "Collisor.h"
#include "LevelStateHandler.h"
#include "ObstacleList.h"
#include "HUDModel.h"
class Player;
class Level {
protected:
	HUDModel* hudtexture;
	StaticList platforms;
	EnemiesList enemies;
	ProjectileList projectiles;
	ObstacleList obstacles;
	Collisor collider;
	LevelStateHandler lvlstateh;
	Player* p1;
	Player* p2;
	bool pl2;
	bool finished;
	bool lost;
	sf::RectangleShape hudp1;
	sf::RectangleShape hudp2;
	sf::RectangleShape potion;

public:
	Level();
	virtual void check_collision() = 0;
	void load();
	virtual void load_default() = 0;
	virtual void update(float deltat) = 0;
	virtual void load_static() = 0;
	sf::RectangleShape getCenter();
	void draw(sf::RenderWindow* window);
	void setP1ref(Player* p1);
	void setP2ref(Player* p2);
	Player* getP1ref() { return p1; }
	Player* getP2ref() { return p2; }
	const bool getFinished() const { return finished; }
	const bool getLost() const { return lost; }
	void setLost();
	void savePoints();
	void save();
	void clear();
	LevelStateHandler* getStateHandler() { return &lvlstateh; }
	virtual void setFinished() = 0;
};