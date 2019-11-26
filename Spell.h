#pragma once
#include "Projectile.h"
#include "SpellsModel.h"
#include "Animation.h"
using namespace Models;
using namespace AbstractEntity;
class Spell : public Projectile, public Animation
{
protected:
	SpellsModel* textures;
	bool hitable;
	bool active;
public:
	Spell(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento) : Projectile(size, pos, speed, hitbox, deslocamento) { hitable = false; active = true; textures = nullptr; }
	~Spell(){textures = nullptr;}
	virtual void update(float deltat) = 0;
	const bool getHitable() const { return hitable; }
	const bool getActive() const { return active; }
	void setHitable(const bool hitable) { this->hitable = hitable; }
	void onCollision(sf::Vector2f direction);
};

