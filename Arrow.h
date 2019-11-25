#pragma once
#include "Projectile.h"
#include "ArrowModel.h"
#include "Animation.h"

using namespace Models;
using namespace AbstractEntity;

class Player;
class Arrow : public Projectile
{
private:
	ArrowModel* texture;
	Player* origem;
	sf::Vector2f velocity;
public:
	void setShooter(Player* shooter) { origem = shooter; }
	Arrow(sf::Vector2f pos, sf::Vector2f speed,Player* pref);
	void update(float deltat);
	const sf::Vector2f getVelocity() const { return velocity; }
	Player* getShooter() { return origem; }
	void flip() { velocity.x *= -1; }
};

