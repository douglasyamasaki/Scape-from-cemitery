#include "Collisor.h"
#include "Body.h"
#include "Player.h"
#include "EnemiesList.h"
#include "StaticList.h"
#include "ProjectileList.h"
#include "ObstacleList.h"
#include "Spell.h"
#include "Ghost.h"
#include "Arrow.h"
#include "Mine.h"
#include "Tombstone.h"
#include "Platform.h"
#include "Fireball.h"

bool Collisor::CheckCollision(Body* thisbody, Body* other, sf::Vector2f& direction, float push)
{
	sf::Vector2f otherPos = other->getHBPos();
	sf::Vector2f otherHalfSize = other->getHalfsize();
	sf::Vector2f thisPosition = thisbody->getHBPos();
	sf::Vector2f thisHalfSize = thisbody->getHalfsize();


	float deltax = otherPos.x - thisPosition.x;
	float deltay = otherPos.y - thisPosition.y;
	float interX = abs(deltax) - (otherHalfSize.x + thisHalfSize.x);
	float interY = abs(deltay) - (otherHalfSize.y + thisHalfSize.y);

	if (interX < 0.0f && interY < 0.0f) {
		push = std::min(std::max(push, 0.0f), 1.0f); 
		if (interX > interY) {
			if (interX < -0.2)
				interX = -0.2;
			if (deltax > 0.0f) {
				thisbody->moveHB(interX * (1.0f - push), 0.0f);
				other->moveHB(-interX * push, 0.0f);
				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else {
				thisbody->moveHB(-interX * (1.0f - push), 0.0f);
				other->moveHB(interX * push, 0.0f);
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else {
			if (interY < -0.2)
				interY = -0.2;
			if (deltay > 0.0f) {
				thisbody->moveHB(0.0f, interY * (1.0f - push));
				other->moveHB(0.0f, -interY * push);
				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else {
				thisbody->moveHB(0.0f, -interY * (1.0f - push));
				other->moveHB(0.0f, interY * push);
				direction.x = 0.0f;
				direction.y = -1.0f;
			}

		}
		return true;
	}
	return false;
}


void Collisor::CollidePlayerObstacle()
{
	for (obstacles->it = obstacles->getPrimeiro(); obstacles->it.getIt() != nullptr; obstacles->it++) {
		Tombstone* tombptr = dynamic_cast<Tombstone*>(obstacles->it.getIt()->getInfo());
		Mine* mineptr = dynamic_cast<Mine*>(obstacles->it.getIt()->getInfo());
		sf::Vector2f direction = sf::Vector2f(0.0f, 0.0f);
		if (CheckCollision(obstacles->it.getIt()->getInfo(), p1r, direction, 1.0f)) {
			if (tombptr != nullptr) {
				obstacles->remove();
			}
			else if (mineptr != nullptr) {
				obstacles->remove();
				p1r->onHit(direction);
			}
			else {
				p1r->onHit(direction);
			}
		}
		if (p2r != nullptr) {
			if (CheckCollision(obstacles->it.getIt()->getInfo(), p2r, direction, 1.0f)) {
				if (tombptr != nullptr) {
					obstacles->remove();
				}
				if (mineptr != nullptr) {
					obstacles->remove();
					p2r->onHit(direction);
				}
				else {
					p2r->onHit(direction);
				}
			}
		}
	}
}

void Collisor::CollidePlayerPlatform()
{
	
	for (statics->it = statics->getPrimeiro(); statics->it.getIt() != nullptr; statics->it++) {
		sf::Vector2f direction = sf::Vector2f(0.0f, 0.0f);
		Body* bodyptr = dynamic_cast<Body*>(statics->it.getIt()->getInfo());
		if (bodyptr != nullptr) {
			if (p1r != nullptr) {
				if (CheckCollision(bodyptr, p1r->getBody(), direction, 1.0f))
					p1r->OnCollision(direction);
			}
			if (p2r != nullptr) {
				if (CheckCollision(bodyptr, p2r->getBody(), direction, 1.0f))
					p2r->OnCollision(direction);
			}
		}
	}
}


void Collisor::CollidePlayerEnemie()
{
	for (enemies->it = enemies->getPrimeiro(); enemies->it.getIt() != nullptr; enemies->it++) {
		sf::Vector2f direction = sf::Vector2f(0.0f, 0.0f);
		if (p1r != nullptr) {
			if (CheckCollision(p1r, enemies->it.getIt()->getInfo()->getBody(), direction, 1.0f)){
				p1r->onHit(direction);
				enemies->it.getIt()->getInfo()->onHit(direction);
			}
				
		}
		if (p2r != nullptr)
			if (CheckCollision(p2r, enemies->it.getIt()->getInfo()->getBody(), direction, 1.0f))
				p2r->onHit(direction);
		if (enemies->it.getIt()->getInfo()->getVidas() <= 0)
			enemies->remove();
	}
}

void Collisor::CollideEnemiePlatform()
{
	for (statics->it = statics->getPrimeiro(); statics->it.getIt() != nullptr; statics->it++) {
		Body* bodyptr = dynamic_cast<Body*>(statics->it.getIt()->getInfo());
		sf::Vector2f direction = sf::Vector2f(0.0f, 0.0f);
		if (bodyptr != nullptr) {
			for (enemies->it = enemies->getPrimeiro(); enemies->it.getIt() != nullptr; enemies->it++) {
				Ghost* ghostptr = dynamic_cast<Ghost*>(enemies->it.getIt()->getInfo());
				if (ghostptr == nullptr){
					if (CheckCollision(bodyptr, enemies->it.getIt()->getInfo()->getBody(), direction, 1.0f))
						enemies->it.getIt()->getInfo()->OnCollision(direction);
				}

			}
		}
	}
}

void Collisor::CollideProjectilePlatform()
{
	for (statics->it = statics->getPrimeiro(); statics->it.getIt() != nullptr; statics->it++) {
		Body* bodyptr = dynamic_cast<Body*>(statics->it.getIt()->getInfo());
		sf::Vector2f direction = sf::Vector2f(0.0f, 0.0f);
		if (bodyptr != nullptr) {
			for (projectiles->it = projectiles->getPrimeiro(); projectiles->it.getIt() != nullptr; projectiles->it++) {
				Spell* spellptr = dynamic_cast<Spell*>(projectiles->it.getIt()->getInfo());
				if (spellptr == nullptr) {
					if (CheckCollision(projectiles->it.getIt()->getInfo()->getBody(), bodyptr, direction, 1.0f))
						projectiles->remove();
				}
				else {
					if (CheckCollision(projectiles->it.getIt()->getInfo()->getBody(), bodyptr, direction, 1.0f))
						spellptr->onCollision(direction);
				}
			}
			Platform* pltaux = dynamic_cast<Platform*>(statics->it.getIt()->getInfo());
			if (pltaux != nullptr)
				pltaux->fix();
		}
	}
}

void Collisor::CollideProjectilePlayer()
{
	for (projectiles->it = projectiles->getPrimeiro(); projectiles->it.getIt() != nullptr; projectiles->it++) {
		sf::Vector2f direction = sf::Vector2f(0.0f, 0.0f);
		Spell* spellptr = dynamic_cast<Spell*>(projectiles->it.getIt()->getInfo());
		Fireball* fireballptr = dynamic_cast<Fireball*>(projectiles->it.getIt()->getInfo());
		if (spellptr != nullptr) {
			if (p1r != nullptr) {
				if (!p1r->getInvulneravel())
					if (spellptr->getHitable())
						if (CheckCollision(p1r, projectiles->it.getIt()->getInfo(), direction, 1.0f))
							p1r->onHit(direction);
			}
			if (p2r != nullptr) {
				if (!p1r->getInvulneravel())
					if (CheckCollision(p2r, projectiles->it.getIt()->getInfo(), direction, 1.0f))
						p2r->onHit(direction);
			}
		}
		if (fireballptr != nullptr) {
			if (p1r != nullptr) {
				if (!p1r->getInvulneravel())
					if (CheckCollision(p1r, projectiles->it.getIt()->getInfo(), direction, 1.0f)){
						p1r->onHit(direction);
						projectiles->remove();
					}
			}
			if (p2r != nullptr) {
				if (!p1r->getInvulneravel())
					if (CheckCollision(p2r, projectiles->it.getIt()->getInfo(), direction, 1.0f)) {
						p2r->onHit(direction);
						projectiles->remove();
					}	
			}
		}
	}
}

void Collisor::CollideProjectileEnemie()
{
	for (projectiles->it = projectiles->getPrimeiro(); projectiles->it.getIt() != nullptr; projectiles->it++) {
		Arrow* arrowptr = dynamic_cast<Arrow*>(projectiles->it.getIt()->getInfo());
		if (arrowptr != nullptr) {
			for (enemies->it = enemies->getPrimeiro(); enemies->it.getIt() != nullptr; enemies->it++) {
				sf::Vector2f direction = sf::Vector2f(0.0f, 0.0f);
				if (CheckCollision(arrowptr, enemies->it.getIt()->getInfo(), direction, 1.0f)) {
					enemies->it.getIt()->getInfo()->onHit(direction);
					arrowptr->getShooter()->increasePoints(enemies->it.getIt()->getInfo()->getReward());
					if (enemies->it.getIt()->getInfo()->getVidas() == 0)
						enemies->remove();
					projectiles->remove();
				}
			}
		}
	}
}

Collisor::Collisor()
{
	this->projectiles = nullptr;
	this->enemies = nullptr;
	this->statics = nullptr;
	this->p1r = nullptr;
	this->p2r = nullptr;
}
