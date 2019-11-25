#pragma once
#include "Spell.h"
class Spark : public Spell
{
private:
public:
	Spark(sf::Vector2f pos);
	void update(float deltat);
};

