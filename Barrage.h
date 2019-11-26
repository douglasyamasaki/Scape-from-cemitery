#pragma once
#include "Spell.h"
class Barrage : public Spell
{
private:
public:
	Barrage(sf::Vector2f pos);
	~Barrage();
	void update(float deltat);
};

