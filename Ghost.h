#pragma once
#include "Enemie.h"
#include "GhostModel.h"

class Player;
using namespace Models;
using namespace AbstractEntity;
class Ghost : public Enemie
{
private:
	static int quantity;
	Player* target;
	GhostModel* texture;
	sf::Vector2f movedirection;
public:
	void setTarget(Player* plr) { this->target = plr; }
	void seek();
	void onHit(sf::Vector2f direction);
	void update(float deltat);
	Ghost(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento, const float reward,Player* p1);
};

