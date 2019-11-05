#pragma once
#include "Listas.h"
using namespace Lists;
class Player;
class Level {
protected:
	StaticList platforms;
	EnemieList enemies;
	ProjectileList projectiles;
	Player* p1;
	Player* p2;
	bool pl2;

public:
	Level() { p1 = nullptr; p2 = nullptr; p2 = false; }
	virtual void check_collision() = 0;
	virtual void load_default() = 0;
	virtual void update(float deltat) = 0;
	virtual void load_static() = 0;
	void draw(sf::RenderWindow* window) {
		for (platforms.it = platforms.getPrimeiro(); platforms.it.getIt() != nullptr; platforms.it++) {
			window->draw(*platforms.it.getIt()->getInfo());
		}
		for (enemies.it = enemies.getPrimeiro(); enemies.it.getIt() != nullptr; enemies.it++) {
			window->draw(*enemies.it.getIt()->getInfo());
		}
		for (projectiles.it = projectiles.getPrimeiro(); projectiles.it.getIt() != nullptr; projectiles.it++) {
			window->draw(*projectiles.it.getIt()->getInfo());
		}
	}
	void setP2() { pl2 = true; }
	Player* getP1ref() { return p1; }
	Player* getP2ref() { return p2; }
};