#include "FirstLevel.h"
#include "Platform.h"
#include "Player.h"
#include "Ghost.h"
#include "Arrow.h"
#include "Warlock.h"
#include "Spell.h"
FirstLevel::FirstLevel() : Level()
{
}
void FirstLevel::check_collision()
{
	// collision section
	for (platforms.it = platforms.getPrimeiro(); platforms.it.getIt() != nullptr; platforms.it++) {
		sf::Vector2f direction;
		// Colisao de inimigo com player e inimigo com as plataformas
		direction = sf::Vector2f(0, 0);
		for (enemies.it = enemies.getPrimeiro(); enemies.it.getIt() != nullptr; enemies.it++) {
			Ghost* ghstptr = dynamic_cast<Ghost*>(enemies.it.getIt()->getInfo());
			if (ghstptr == nullptr) {
				if (platforms.it.getIt()->getInfo()->getCollisor()->CheckCollision(enemies.it.getIt()->getInfo()->getCollisor(), direction, 1.0f))
					enemies.it.getIt()->getInfo()->OnCollision(direction);
			}
			if (!p1->getInvulneravel())
				if (enemies.it.getIt()->getInfo()->getCollisor()->CheckCollision(p1->getCollisor(), direction, 1.0f)){
					p1->onHit(direction); // on hit
					enemies.it.getIt()->getInfo()->onHit(direction);
					if (enemies.it.getIt()->getInfo()->getVidas() == 0)
						enemies.remove();
				}
			if (p2 != nullptr) {
				if (!p2->getInvulneravel())
					if (enemies.it.getIt()->getInfo()->CheckCollision(p2->getCollisor(), direction, 1.0f)){
						p2->OnCollision(direction);
						enemies.it.getIt()->getInfo()->onHit(direction);
						if (enemies.it.getIt()->getInfo()->getVidas() == 0)
							enemies.remove();
				}
			}
		}
		direction = sf::Vector2f(0, 0);
		//colisao de plataforma com flechas
		for (projectiles.it = projectiles.getPrimeiro(); projectiles.it.getIt() != nullptr; projectiles.it++) {
			Spell* spellptr = dynamic_cast<Spell*>(projectiles.it.getIt()->getInfo());
			if (spellptr == nullptr){
				if (platforms.it.getIt()->getInfo()->CheckCollision(projectiles.it.getIt()->getInfo()->getCollisor(), direction, 1.0f))
					projectiles.remove();
			}
			else {
				if (platforms.it.getIt()->getInfo()->CheckCollision(projectiles.it.getIt()->getInfo()->getCollisor(), direction, 1.0f))
					spellptr->onCollision(direction);
			}
				
		}
		direction = sf::Vector2f(0, 0);
		// Colisao de plataforma com players
		platforms.it.getIt()->getInfo()->getCollisor()->CheckCollision(p1->getCollisor(), direction, 1.0f);
		p1->OnCollision(direction);
		if (p2 != nullptr) {
			platforms.it.getIt()->getInfo()->getCollisor()->CheckCollision(p2->getCollisor(), direction, 1.0f);
			p2->OnCollision(direction);
		}
	}
	//colisao de projeteis : (fase 1 nao tem boss , ou seja , nao tem ref a player
	for (projectiles.it = projectiles.getPrimeiro(); projectiles.it.getIt() != nullptr; projectiles.it++) {
		sf::Vector2f direction;
		direction = sf::Vector2f(0, 0);
		Arrow* arrowptr = dynamic_cast<Arrow*>(projectiles.it.getIt()->getInfo());
		for (enemies.it = enemies.getPrimeiro(); enemies.it.getIt() != nullptr; enemies.it++) {
			if (projectiles.it.getIt()->getInfo()->getCollisor()->CheckCollision(enemies.it.getIt()->getInfo()->getCollisor(), direction, 1.0f)) {
				enemies.it.getIt()->getInfo()->onHit(direction);
				arrowptr->getAtirador()->increasePoints(enemies.it.getIt()->getInfo()->getReward());
				if (enemies.it.getIt()->getInfo()->getVidas() == 0){
					enemies.remove();
				}
				projectiles.remove();
			}
		}

	}
	projectiles.manageSpells();
}
void FirstLevel::load_static()
{
	Platform* chao = new Platform(sf::Vector2f(10000, 1000), sf::Vector2f(0, 0));
	platforms + chao;
	Warlock* wlk = new Warlock(sf::Vector2f(250, 200), sf::Vector2f(100, -300), sf::Vector2f(100, 0), sf::Vector2f(101, 131), sf::Vector2f(15, -20), 1000,&projectiles);
	wlk->setP1(p1);
	enemies + wlk;
}

void FirstLevel::load_default() {
	p1 = new Player(sf::Vector2f(250,200), sf::Vector2f(0,-300), sf::Vector2f(100,0),sf::Vector2f(101,131), sf::Vector2f(15,-20),&projectiles);
	load_static();
	
}

void FirstLevel::update(float deltat)
{
	p1->update(deltat);
	if (p2 != nullptr)
		p2->update(deltat);
	// update section
	for (enemies.it = enemies.getPrimeiro(); enemies.it.getIt() != nullptr; enemies.it++) {
		enemies.it.getIt()->getInfo()->update(deltat);
	}
	for (projectiles.it = projectiles.getPrimeiro(); projectiles.it.getIt(); projectiles.it++) {
		projectiles.it.getIt()->getInfo()->update(deltat);
	}
	check_collision();
}
