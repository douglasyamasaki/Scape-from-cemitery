#include "Spark.h"

Spark::Spark(sf::Vector2f pos) : Spell (sf::Vector2f(250, 200),pos, sf::Vector2f(0, 500), sf::Vector2f(20, 131), sf::Vector2f(15, -20))
{
	textures = SpellsModel::getInstance();
	setTexture(textures->getSpell1());
	load(textures->getSpell1(), sf::Vector2u(7, 2), 0.05);
	setLock();
	active = true;
}

void Spark::update(float deltat)
{
	hitbox.setFillColor(sf::Color::Blue);
	Refresh(deltat);
	setTextureRect(uvRect);
	moveHB(speed.x * deltat, speed.y * deltat);
	setPosition(hitbox.getPosition().x - deslocamento.x, hitbox.getPosition().y + deslocamento.y);
	if (!getLock())
		active = false;
	if (frames > 9)
		hitable = true;
}
