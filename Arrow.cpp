#include "Arrow.h"

Arrow::Arrow(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f displacement,Player* pref) : Projectile(size, pos, speed, hitbox, displacement)
{
	texture = ArrowModel::getInstance();
	setTexture(texture->getArrow());
	velocity = speed;
	load(texture->getArrow(), sf::Vector2u(1, 1), 0.1);
	origin = pref;
}

void Arrow::update(float deltat)
{
	velocity.y += 981.0f * deltat;
	moveHB(velocity.x * deltat, velocity.y * deltat);
	setPosition(hitbox.getPosition() - displacement);
	Refresh(deltat);
	setTextureRect(uvRect);
	if (velocity.x != 0) {
		setRotation( velocity.y / velocity.x * 45);
		hitbox.setRotation(velocity.y / velocity.x * 45);
		if (velocity.x < 500){
			setRotation(velocity.y / velocity.x * 25);
			hitbox.setRotation(velocity.y / velocity.x * 25);
		}
	}
}