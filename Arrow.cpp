#include "Arrow.h"
Arrow::Arrow(sf::Vector2f pos, sf::Vector2f speed, Player* pref) : Projectile(sf::Vector2f(120, 15), pos, speed, sf::Vector2f(120, 50), sf::Vector2f(0, 0))
{
	texture = ArrowModel::getInstance();
	setTexture(texture->getArrow());
	velocity = speed;
	origem = pref;
}

void Arrow::update(float deltat)
{
	velocity.y += 981.0f * deltat;
	moveHB(velocity.x * deltat, velocity.y * deltat);
	setPosition(hitbox.getPosition() - deslocamento);
	if (velocity.x != 0) {
		setRotation( velocity.y / velocity.x * 45);
		hitbox.setRotation(velocity.y / velocity.x * 45);
		if (velocity.x < 500){
			setRotation(velocity.y / velocity.x * 25);
			hitbox.setRotation(velocity.y / velocity.x * 25);
		}
	}
}