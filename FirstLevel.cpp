#include "FirstLevel.h"
#include "Platform.h"
#include "Player.h"
#include "Ghost.h"
#include "Arrow.h"
#include "Warlock.h"
#include "Spell.h"
#include "Spike.h"
#include "Dragon.h"
#include "Mine.h"
#include "Tombstone.h"
FirstLevel::FirstLevel() : Level()
{
}

void FirstLevel::check_collision()
{
	collider.CollideProjectilePlatform();
	collider.CollideEnemiePlatform();
	collider.CollidePlayerEnemie();
	collider.CollidePlayerPlatform();
	collider.CollideProjectileEnemie();
	collider.CollideProjectilePlayer();
	collider.CollidePlayerObstacle();
}

void FirstLevel::load_static()
{
	Platform* chao = new Platform(sf::Vector2f(10000, 1000), sf::Vector2f(0, 0));
	platforms + chao;
	lvlstateh.setType(1);
}


void FirstLevel::load_default() {
	load_static();
	p1->setList(&projectiles);
	if (p2 != nullptr){
		p2->setList(&projectiles);
		collider.setP2r(p2);
		p2->setPos(sf::Vector2f(-100, -600));
	}
	
	p1->setPos(sf::Vector2f(-100, -600));
	Warlock* wlkptr = new Warlock(sf::Vector2f(300, -600), &projectiles);
	wlkptr->setP1(p1);
	enemies + wlkptr;
	lvlstateh.setP1(p1);
	collider.setP1r(p1);
	
}

void FirstLevel::update(float deltat)
{
	p1->update(deltat);
	if (p2 != nullptr)
		p2->update(deltat);
	// update section
	projectiles.ManageSpells();
	
	for (enemies.it = enemies.getPrimeiro(); enemies.it.getIt() != nullptr; enemies.it++) {
		enemies.it.getIt()->getInfo()->update(deltat);
	}
	for (projectiles.it = projectiles.getPrimeiro(); projectiles.it.getIt(); projectiles.it++) {
		projectiles.it.getIt()->getInfo()->update(deltat);
	}
	check_collision();
	setLost();
	setFinished();
}

void FirstLevel::setFinished()
{
	if (p1->getPosition().x > 2000)
		finished = true;
}
