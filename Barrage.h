#pragma once
#include "Spell.h"
class Barrage : public Spell
{
private:
public:
	Barrage(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento);
	void update(float deltat);
};

