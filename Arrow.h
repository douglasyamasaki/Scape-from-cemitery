#pragma once
#include "Projectile.h"
#include "Models.h"
#include "Animation.h"

using namespace SpriteModels;
using namespace AbstractEntitys;

class Player;
class Arrow : public Projectile, public Animation
{
private:
	ArrowModel* texture;
	Player* origem;
	sf::Vector2f velocity;
public:
	
	Arrow(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento,Player* pref);
	void update(float deltat);
	Player* getAtirador() { return origem; }
	void flip() { velocity.x *= -1; }
};

