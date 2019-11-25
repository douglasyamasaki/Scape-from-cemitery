#pragma once
#include "Projectile.h"
#include "FireballModel.h"
using namespace AbstractEntity;
class Fireball : public Projectile
{
private:
	FireballModel* instance;
public:
	void flip() { speed.x *= -1; }
	Fireball(sf::Vector2f pos);
	void update(float deltat);
};

