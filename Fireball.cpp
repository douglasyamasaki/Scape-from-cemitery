#include "Fireball.h"

Fireball::Fireball(sf::Vector2f pos) : Projectile (sf::Vector2f(50.0f,50.0f),pos,sf::Vector2f(600,0),sf::Vector2f(50.0f,50.0f),sf::Vector2f(0.0f,0.0f))
{
	instance = FireballModel::getInstance();
	setTexture(instance->getFireball());
}

void Fireball::update(float deltat)
{
	moveHB(speed.x * deltat, speed.y * deltat);
	setPosition(hitbox.getPosition() - deslocamento);
}
