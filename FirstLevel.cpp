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
	collider.CollideProjectilePlatform();
	collider.CollideEnemiePlatform();
	collider.CollidePlayerEnemie();
	collider.CollidePlayerPlatform();
	collider.CollideProjectileEnemie();
	collider.CollideProjectilePlayer();
}

void FirstLevel::load_static()
{
	Platform* chao = new Platform(sf::Vector2f(10000, 1000), sf::Vector2f(0, 0));
	platforms + chao;
	Warlock* wlk = new Warlock(sf::Vector2f(250, 200), sf::Vector2f(200, -300), sf::Vector2f(100, 0), sf::Vector2f(101, 131), sf::Vector2f(15, -20), 1000, &projectiles);
	wlk->setP1(p1);
	enemies + wlk;
	collider.setEnemiesList(&enemies);
	collider.setProjectileList(&projectiles);
	collider.setStaticList(&platforms);
	collider.setP1r(p1);
}

void FirstLevel::load_default() {
	p1 = new Player(sf::Vector2f(250,200), sf::Vector2f(0,-600), sf::Vector2f(100,0),sf::Vector2f(101,131), sf::Vector2f(15,-20),&projectiles);
	load_static();
	
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
}
