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
	static int getQuantity()  { return quantity; }
	const sf::Vector2f getMoveDirection() const { return movedirection; }
	void setMoveDirection(const sf::Vector2f movedirection) { this->movedirection = movedirection; }
	void setTarget(Player* plr) { this->target = plr; }
	void seek();
	void onHit(sf::Vector2f direction);
	void update(float deltat);
	Player* getTarget() const { return target; }
	Ghost(sf::Vector2f pos,Player* p1);
	~Ghost() { quantity--; }
};

