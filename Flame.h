#pragma once
#include "Spell.h"

class Flame : public Spell
{
private:
public:
	Flame(sf::Vector2f pos);
	~Flame(){delete(instance);}
	void update(float deltat);
};

