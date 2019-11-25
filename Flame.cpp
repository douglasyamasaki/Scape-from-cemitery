#include "Flame.h"

Flame::Flame(sf::Vector2f pos) : Spell (sf::Vector2f(250, 200),pos, sf::Vector2f(0, 500), sf::Vector2f(20, 131), sf::Vector2f(15, -20))
{
	textures = SpellsModel::getInstance();
	setTexture(textures->getSpell2());
	load(textures->getSpell2(), sf::Vector2u(9, 2), 0.05);
	setLock();
	active = true;
}

void Flame::update(float deltat)
{
	Refresh(deltat);
	setTextureRect(uvRect);
	moveHB(speed.x * deltat, speed.y * deltat);
	setPosition(hitbox.getPosition().x - deslocamento.x, hitbox.getPosition().y + deslocamento.y);
	if (!getLock())
		active = false;
	if (frames > 9)
		hitable = true;
}
