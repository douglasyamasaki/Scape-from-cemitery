#include "Barrage.h"
Barrage::Barrage(sf::Vector2f pos) : Spell (sf::Vector2f(250, 200),pos,sf::Vector2f(0, 500), sf::Vector2f(20, 131), sf::Vector2f(15, -20))
{
	textures = SpellsModel::getInstance();
	setTexture(textures->getSpell3());
	load(textures->getSpell3(), sf::Vector2u(8, 2), 0.05);
	setLock();
	active = true;
}

void Barrage::update(float deltat)
{
	Refresh(deltat);
	setTextureRect(uvRect);
	moveHB(speed.x * deltat, speed.y * deltat);
	setPosition(hitbox.getPosition().x - deslocamento.x, hitbox.getPosition().y + deslocamento.y);
	if (!getLock())
		active = false;
	if (frames > 13)
		hitable = true;
}
