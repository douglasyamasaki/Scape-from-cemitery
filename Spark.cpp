#include "Spark.h"

Spark::Spark(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento) : Spell (size,pos,speed,hitbox,deslocamento)
{
	textures = SpellsModel::getInstance();
	setTexture(textures->getSpell3());
	load(textures->getSpell3(), sf::Vector2u(9, 2), 0.1);
	setLock();
	active = true;
}

void Spark::update(float deltat)
{
	Refresh(deltat);
	setTextureRect(uvRect);
	moveHB(speed.x * deltat, speed.y * deltat);
	if (!getLock())
		active = false;
	if (frames > 9)
		hitable = true;
}
