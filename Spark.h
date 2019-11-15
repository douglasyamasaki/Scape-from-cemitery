#pragma once
#include "Spell.h"
class Spark : public Spell
{
private:
public:
	Spark(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento);
	void update(float deltat);
};

