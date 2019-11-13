#include "Spell.h"
#include "Models.h"
using namespace SpriteModels;

Spell::Spell(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f displacement,int type) : Projectile (size,pos,speed,hitbox,displacement) , Animation ()
{
	textures = SpellModel::getInstance();
	this->type = type;
	float stime;
	sf::Texture* ref = nullptr;
	sf::Vector2u vec;
	active = true;
	switch (type) {
	case 1:
		ref = textures->getSpell1();
		setTexture(textures->getSpell1());
		stime = 0.05;
		vec = sf::Vector2u(7,2);
		break;
	case 2:
		ref = textures->getSpell2();
		setTexture(textures->getSpell2());
		stime = 0.1;
		vec = sf::Vector2u(9, 2);
		break;
	case 3:
		ref = textures->getSpell3();
		setTexture(textures->getSpell3());
		stime = 0.035;
		vec = sf::Vector2u(8, 2);
		break;
	}
	load(ref,vec, stime);
	setLock();

}

void Spell::update(float deltat)
{
	Refresh(deltat);
	setTextureRect(uvRect);
	moveHB(speed.x * deltat, speed.y * deltat);
	setPosition(hitbox.getPosition().x - displacement.x, hitbox.getPosition().y + displacement.y);
	if (!getLock())
		active = false;
	switch (type) {
	case 1:
		if (frames > 8)
			hitable = true;
		break;
	case 2:
		if (frames > 8)
			hitable = true;
		break;
	case 3:
		if (frames > 10)
			hitable = true;
		break;

	}
}

void Spell::onCollision(sf::Vector2f direction)
{
	speed.y = 0;
}

