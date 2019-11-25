#pragma once
#include "Spell.h"

class Flame : public Spell
{
private:
public:
	Flame(sf::Vector2f pos);
	void update(float deltat);
};

