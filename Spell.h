#pragma once
#include "Projectile.h"
#include "Models.h"
#include "Animation.h"
using namespace SpriteModels;

class Spell : public Projectile, public Animation
{
private:
	SpellModel* textures;
	int type;
	bool hitable;
	bool active;
public:
	Spell(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f displacement, int type);
	void update(float deltat);
	const bool getHitable() const { return hitable; }
	const bool getActive() const { return active; }
	void onCollision(sf::Vector2f direction);

};

