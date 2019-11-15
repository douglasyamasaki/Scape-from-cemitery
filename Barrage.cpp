#include "Barrage.h"

Barrage::Barrage(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento) : Spell (size,pos,speed,hitbox,deslocamento)
{
	textures = SpellsModel::getInstance();
	setTexture(textures->getSpell3());
	load(textures->getSpell3(), sf::Vector2u(8, 2), 0.1);
	setLock();
	active = true;
}

void Barrage::update(float deltat)
{
	Refresh(deltat);
	setTextureRect(uvRect);
	moveHB(speed.x * deltat, speed.y * deltat);
	if (!getLock())
		active = false;
	if (frames > 13)
		hitable = true;
}
