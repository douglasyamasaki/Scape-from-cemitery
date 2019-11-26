#include "Dragon.h"
#include "Fireball.h"
#include "Player.h"
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
	sf::Vector2f aux = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f aux2 = sf::Vector2f(0.0f, 0.0f);
	if (p1t != nullptr)
		aux = p1t->getHBPos() - getHBPos();
	if (p2t != nullptr)
		aux2 = p2t->getHBPos() - getHBPos();
	if (aux.x < aux2.x)
		movdirection = aux;
	else
		movdirection = aux2;
	if (movdirection.x < 0)
		faceright = false;
	else
		faceright = true;

}

void Dragon::update(float deltat)
{
	seek();
	accumulator += deltat;
	if (accumulator >= 4.5f && frames == 9 && abs(movdirection.x) < 900){
		accumulator *= 0.0f;
		Fireball* fireballptr = new Fireball(getPosition());
		if (!faceright)
			fireballptr->flip();
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
