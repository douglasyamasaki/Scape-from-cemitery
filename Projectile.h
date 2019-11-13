#pragma once
#include "AbstractEntitys.h"
using namespace AbstractEntitys;

class Projectile : public DynamicEntity{
private:
public:
	Projectile(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f displacement) :
		DynamicEntity(size, pos, speed, hitbox, displacement) {

	}
	virtual void update(float deltat) = 0;
};