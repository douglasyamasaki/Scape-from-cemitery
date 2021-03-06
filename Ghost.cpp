#include "Ghost.h"
#include "Player.h"
int Ghost::quantity = 0;

void Ghost::seek()
{
	movedirection.x = target->getPosition().x - getPosition().x;
	movedirection.y = target->getPosition().y - getPosition().y;
}

void Ghost::update(float deltat)
{
	seek();
	if (target->getDead())
		vidas--;
	if (movedirection.x < 0.0f) {
		faceright = true;
		velocity.x -= speed.x;
	}
	else {
		faceright = false;
		velocity.x += speed.x;
	}
	if (movedirection.y > 0.0f) {
		velocity.y += speed.y;
	}
	else {
		velocity.y -= speed.y;
	}
	if (!faceright)
		setPosition(hitbox.getPosition().x - deslocamento.x, hitbox.getPosition().y + deslocamento.y);
	else
		setPosition(hitbox.getPosition().x + deslocamento.x, hitbox.getPosition().y + deslocamento.y);
	Refresh(deltat);
	setTextureRect(uvRect);
	moveHB(velocity.x * deltat, velocity.y * deltat);
	velocity.x *= 0.0f;
	velocity.y *= 0.0f;
}


Ghost::Ghost(sf::Vector2f pos, Player* p1) :
	Enemie(sf::Vector2f(140, 90),pos, sf::Vector2f(100, 100), sf::Vector2f(140, 90), sf::Vector2f(0, 0),500)
{
	vidas = 1;
	setTarget(p1);
	texture = GhostModel::getInstance();
	load(texture->getGhost(), sf::Vector2u(3, 5), 0.1);
	setTexture(texture->getGhost());
	quantity++;
}

void Ghost::onHit(sf::Vector2f direction) {
	vidas--;
}
