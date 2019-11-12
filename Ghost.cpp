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
	if (movedirection.x < 0.0f) {
		faceright = true;
		velocity.x += speed.x;
	}
	else {
		faceright = false;
		velocity.x -= speed.x;
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

Ghost::Ghost(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento, const float reward,Player* p1) :
	Inimigo(size,pos,speed,hitbox,deslocamento,reward)
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
