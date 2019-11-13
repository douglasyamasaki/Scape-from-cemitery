#pragma once
#include "Inimigo.h"
#include "Models.h"

class Player;
using namespace SpriteModels;
class Ghost : public Inimigo
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
	Ghost(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f displacement, const float reward,Player* p1);
};

