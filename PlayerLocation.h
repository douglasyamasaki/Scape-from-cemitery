#pragma once
#include "Player.h"
class PlayerLocation {
private:
	Player* p1;
	Player* p2;
public:
	sf::Vector2f getP1() { return p1->getPosition(); }
	sf::Vector2f getP2() { return p2->getPosition(); }
};
