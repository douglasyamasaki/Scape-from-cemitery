#include "Dragon.h"
#include "Fireball.h"

Dragon::Dragon(sf::Vector2f pos) : Enemie (sf::Vector2f(200,200),pos, sf::Vector2f(0.0f,0.0f),sf::Vector2f(75.0f,100.0f),sf::Vector2f(10.0f,-30.0f),1000)
{
	texture = DragonModel::getInstance();
	setTexture(texture->getDragon());
	load(texture->getDragon(), sf::Vector2u(2, 6), 0.1);
	vidas = 3;
	p1t = nullptr;
	p2t = nullptr;
	velocity = sf::Vector2f(0.0f, 0.0f);
	accumulator = 0;
}

void Dragon::onHit(sf::Vector2f direction)
{
	vidas--;
}

void Dragon::seek()
{

}

void Dragon::update(float deltat)
{
	accumulator += deltat;
	if (accumulator += deltat);
	if (accumulator >= 4.5f && frames == 9) {
		accumulator -= 4.5f;
		Fireball* fireballptr = new Fireball(getPosition());
		*listref + fireballptr;
	}
	if (!faceright)
		setPosition(hitbox.getPosition().x - deslocamento.x, hitbox.getPosition().y + deslocamento.y);
	else
		setPosition(hitbox.getPosition().x + deslocamento.x, hitbox.getPosition().y + deslocamento.y);
	Refresh(deltat);
	setTextureRect(uvRect);
	moveHB(velocity.x * deltat, velocity.y * deltat);
}
