#include "Warlock.h"
#include "Player.h"
#include "Spark.h"
#include "Barrage.h"
#include "Flame.h"

void Warlock::UpdateTexture()
{
	if (!getLock()) {
		if ((velocity.x > 0.0f || velocity.x < 0.0f) && !getLock())
			setTexture(textures->getWalk());
		else if (velocity.x == 0.0f && !getLock())
			setTexture(textures->getIdle());
	}
}

void Warlock::seek()
{
	sf::Vector2f p1v;
	sf::Vector2f p2v;
	if (p1 != nullptr)
		p1v.x = p1->getPosition().x - getPosition().x;
	if (p2 != nullptr)
		p2v.x = p2->getPosition().x - getPosition().x;
	if (p2 == nullptr)
		movdirection = p1v;
	else {
		if (p1v.x < p2v.x)
			movdirection = p1v;
		else
			movdirection = p2v;
	}
	if (movdirection.x > 500 || movdirection.x < -500)
		movdirection.x = 0;
}

void Warlock::attack()
{
	float facerightCorrector  = p1->getPosition().x - getPosition().x;
	if (attacktype == 0)
		return;
	if (facerightCorrector < 0.0f)
		faceright = false;
	sf::Vector2f p1p;
	sf::Vector2f p2p;
	if (p1 != nullptr)
		p1p = p1->getPosition();
	if (p2 != nullptr)
		p2p = p2->getPosition();
	if (attacktype == 1) {
		setTexture(textures->getCast1());
	}
	if (attacktype == 2) {
		setTexture(textures->getCast2());
	}
	if (attacktype == 3) {
		setTexture(textures->getCast3());
	}
	if (attacktype > 0) {
		if (!getLock()){
			attacktype = 0;
			setImgC(sf::Vector2u(6, 4));
			reset();
		}
		if (attacktype == 1 && frames == 19) {
			Spark* sparkptr = new Spark(sf::Vector2f(250, 200), sf::Vector2f(p1p.x, p1p.y - 300), sf::Vector2f(0, 1000), sf::Vector2f(55, 131), sf::Vector2f(15, -20));
			*projeteis + sparkptr;
			frameup();
		}
		if (attacktype == 2 && frames == 41) {
			Flame* barrageptr = new Flame(sf::Vector2f(250, 200), sf::Vector2f(p1p.x, p1p.y - 300), sf::Vector2f(0, 1000), sf::Vector2f(55, 131), sf::Vector2f(15, -20));
			*projeteis + barrageptr;
			frameup();
		}
		if (attacktype == 3 && frames == 17) {
			Barrage* flameptr = new Barrage(sf::Vector2f(250, 200), sf::Vector2f(p1p.x, p1p.y - 300), sf::Vector2f(0, 1000), sf::Vector2f(55, 131), sf::Vector2f(15, -20));
			frameup();
			*projeteis + flameptr;
		}
			
	}
}

void Warlock::randomizeattack()
{
	if (movdirection.x == 0 && movdirection.y == 0) {
		if (attacktype == 0) {
			if (!getLock()){
				attacktype = rand() % 4;
				switch (attacktype) {
				case 1:
					setImgC(sf::Vector2u(6,5));
					break;
				case 2:
					setImgC(sf::Vector2u(6,12));
					break;
				case 3:
					setImgC(sf::Vector2u(6,4));
					break;
				case 0:
					setImgC(sf::Vector2u(6,4));
					break;
				}
				if (attacktype > 0) {
					setLock();
					reset();
				}
			}
		}
	}
}

void Warlock::onHit(sf::Vector2f direction)
{
}

Warlock::Warlock(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento, const float reward, ProjectileList* ref) : 
	Enemie (size,pos,speed,hitbox,deslocamento,reward)
{
	this->projeteis = ref;
	textures = WarlockModel::getInstance();
	load(textures->getIdle(), sf::Vector2u(6,4),0.035);
	attacktype = 0;
	vidas = 25;
	velocity = sf::Vector2f(0.0f, 0.0f);
}

void Warlock::update(float deltat)
{
	seek();
	move();
	UpdateTexture();
	Refresh(deltat);
	setTextureRect(uvRect);
	moveHB(velocity.x * deltat, velocity.y * deltat);
	if (!faceright)
		setPosition(hitbox.getPosition().x - deslocamento.x, hitbox.getPosition().y + deslocamento.y);
	else
		setPosition(hitbox.getPosition().x + deslocamento.x, hitbox.getPosition().y + deslocamento.y);
	velocity.x *= 0.0f;
	velocity.y *= 0.0f;
	randomizeattack();
	attack();
}

void Warlock::move()
{
	if (getLock())
		return;
	if (movdirection.x < 0.0f) {
		faceright = true;
		velocity.x += speed.x;
	}
	else if (movdirection.x > 0.0f) {
		faceright = false;
		velocity.x -= speed.x;
	}
	else if (movdirection.x == 0.0f)
		velocity.x = 0;
}
