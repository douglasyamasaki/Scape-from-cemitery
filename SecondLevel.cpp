#include "SecondLevel.h"
#include "Player.h"
#include "Ghost.h"
#include "Warlock.h"
#include "Platform.h"
#include "TilesetModel.h"
#include "Mine.h"
#include "Tombstone.h"
void SecondLevel::resetlists()
{
	//tombstones
	obstaclesapoints.clear();
	obstaclesapoints.push_back(sf::Vector2f(-400, 98 + 40));
	obstaclesapoints.push_back(sf::Vector2f(-300, 98 + 40));
	obstaclesapoints.push_back(sf::Vector2f(-35, 809 + 40));
	obstaclesapoints.push_back(sf::Vector2f(-1100, 258 + 40));
	obstaclesapoints.push_back(sf::Vector2f(-1320, 638 + 40));
	obstaclesapoints.push_back(sf::Vector2f(-1740, 558 + 40));
	obstaclesapoints.push_back(sf::Vector2f(-2300, 478 + 40));
	obstaclesapoints.push_back(sf::Vector2f(-775, 178 + 40));
	obstaclesapoints.push_back(sf::Vector2f(-500, 98 + 40));
	obstaclesapoints.push_back(sf::Vector2f(-1580, 338 + 40));

	//mines
	obstaclesbpoints.clear();
	obstaclesbpoints.push_back(sf::Vector2f(353, 809 + 37));
	obstaclesbpoints.push_back(sf::Vector2f(-600, 809 + 37));
	obstaclesbpoints.push_back(sf::Vector2f(-1200, 638 + 37));
	obstaclesbpoints.push_back(sf::Vector2f(-2200, 478 + 37));
	obstaclesbpoints.push_back(sf::Vector2f(600, 809 + 37));
	obstaclesbpoints.push_back(sf::Vector2f(-1700, 338 + 37));
	obstaclesbpoints.push_back(sf::Vector2f(-1200, 258 + 37));
	obstaclesbpoints.push_back(sf::Vector2f(-460, 809 + 37));
	obstaclesbpoints.push_back(sf::Vector2f(-890, 178 + 37));
	obstaclesbpoints.push_back(sf::Vector2f(-353, 809 + 37));
	obstaclesbpoints.push_back(sf::Vector2f(460, 809 + 37));

	
}

SecondLevel::SecondLevel()
{
	spawnBoss = false;
	resetlists();
}

void SecondLevel::getBoss()
{
	if (spawnBoss == true && bossref == nullptr) {
		for (enemies.it = enemies.getPrimeiro(); enemies.it != nullptr; enemies.it++) {
			Warlock* wlkptr = dynamic_cast<Warlock*>(enemies.it.getIt()->getInfo());
			if (wlkptr != nullptr) {
				bossref = wlkptr;
				return;
			}
		}
	}
}

void SecondLevel::check_collision()
{
	collider.CollideProjectilePlatform();
	collider.CollideEnemiePlatform();
	collider.CollidePlayerEnemie();
	collider.CollidePlayerPlatform();
	collider.CollideProjectileEnemie();
	collider.CollideProjectilePlayer();
	collider.CollidePlayerObstacle();
}

void SecondLevel::load_static()
{
	TilesetModel* instance = TilesetModel::getInstance();
	Platform* chao = new Platform(sf::Vector2f(10000, 250), sf::Vector2f(-1000, 1000));
	Platform* invisible1 = new Platform(sf::Vector2f(100, 5000), sf::Vector2f(-2400, 809));
	invisible1->setFillColor(sf::Color::Transparent);
	Platform* invisible2 = new Platform(sf::Vector2f(100, 5000), sf::Vector2f(3200, 809));
	invisible2->setFillColor(sf::Color::Transparent);

	Platform* chao2 = new Platform(sf::Vector2f(300, 50), sf::Vector2f(-1200, 729));
	Platform* chao3 = new Platform(sf::Vector2f(350, 50), sf::Vector2f(-1700, 649));
	Platform* chao4 = new Platform(sf::Vector2f(300, 50), sf::Vector2f(-2200, 569));
	Platform* chao5 = new Platform(sf::Vector2f(300, 50), sf::Vector2f(-1700, 429));
	Platform* chao6 = new Platform(sf::Vector2f(300, 50), sf::Vector2f(-1200, 349));
	Platform* chao7 = new Platform(sf::Vector2f(300, 50), sf::Vector2f(-900, 269));
	Platform* chao8 = new Platform(sf::Vector2f(300, 50), sf::Vector2f(-400, 189));
	
	instance->getTile1()->setRepeated(true);

	chao->setTexture(instance->getTile1());
	chao2->setTexture(instance->getTile1());
	chao3->setTexture(instance->getTile1());
	chao4->setTexture(instance->getTile1());
	chao5->setTexture(instance->getTile1());
	chao6->setTexture(instance->getTile1());
	chao7->setTexture(instance->getTile1());
	chao8->setTexture(instance->getTile1());
	chao->setTextureRect(sf::IntRect(0, 0, 10000, 125));
	chao2->setTextureRect(sf::IntRect(0, 0, 300, 125));
	chao3->setTextureRect(sf::IntRect(0, 0, 300, 125));
	chao4->setTextureRect(sf::IntRect(0, 0, 300, 125));
	chao5->setTextureRect(sf::IntRect(0, 0, 300, 125));
	chao6->setTextureRect(sf::IntRect(0, 0, 300, 125));
	chao7->setTextureRect(sf::IntRect(0, 0, 300, 125));
	chao8->setTextureRect(sf::IntRect(0, 0, 300, 125));


	platforms + invisible1;
	platforms + invisible2;
	platforms + chao;
	platforms + chao2;
	platforms + chao3;
	platforms + chao4;
	platforms + chao5;
	platforms + chao6;
	platforms + chao7;
	platforms + chao8;



}

void SecondLevel::load_default()
{
	list<sf::Vector2f>::iterator it;
	load_static();
	p1->setList(&projectiles);
	if (p2 != nullptr) {
		p2->setList(&projectiles);
		collider.setP2r(p2);
		p2->setPos(sf::Vector2f(-900, 809));
	}
	p1->setPos(sf::Vector2f(-900, 809));
	lvlstateh.setP1(p1);
	collider.setP1r(p1);

	ghostqty = rand() % 5;
	ghostqty += 5;
	for (int i = 0; i < ghostqty; i++) {
		int fx = rand() % 5300;
		int fy = rand() % 800;
		int ffx = -2357;
		ffx += fx;
		int randtarget = rand() % 11;
		Ghost* ghstptr = new Ghost(sf::Vector2f(ffx, fy), nullptr);
		if (p2 != nullptr) {
			if (randtarget > 5)
				ghstptr->setTarget(p1);
			else
				ghstptr->setTarget(p2);
		}
		else {
			ghstptr->setTarget(p1);
		}
		enemies + ghstptr;
	}

	int j = rand() % 6;
	j += 5;
	while (j > 0) {
		it = obstaclesbpoints.begin();
		Mine* mineptr = new Mine(*it);
		obstaclesbpoints.pop_front();
		obstacles + mineptr;
		j--;
	}
	j = rand() % 5;
	j += 5;
	while (j > 0) {
		it = obstaclesapoints.begin();
		Tombstone* tombptr = new Tombstone(*it);
		obstaclesapoints.pop_front();
		obstacles + tombptr;
		j--;
	}
	lvlstateh.setGhostQuantity(ghostqty);
	resetlists();
}

void SecondLevel::update(float deltat)
{
	if (Tombstone::getQuantity() == 0 && !spawnBoss) {
		Warlock* wlkptr = new Warlock(sf::Vector2f(300,809), &projectiles);
		wlkptr->setP1(p1);
		wlkptr->setP2(p2);
		bossref = wlkptr;
		spawnBoss = true;
		lvlstateh.setHasSpawned(true);
		enemies + bossref;
	}
	if (Ghost::getQuantity() < ghostqty) {
		int fx = rand() % 5300;
		int fy = rand() % 800;
		int ffx = -2357;
		ffx -= fx;
		int randtarget = rand() % 11;
		Ghost* ghstptr = new Ghost(sf::Vector2f(ffx, fy), nullptr);
		if (p2 != nullptr) {
			if (randtarget > 5)
				ghstptr->setTarget(p1);
			else
				ghstptr->setTarget(p2);
		}
		else {
			ghstptr->setTarget(p1);
		}
		enemies + ghstptr;
	}
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
	getBoss();
}

void SecondLevel::setFinished()
{
	if (bossref != nullptr)
		if (bossref->getVidas() <= 0)
			finished = true;
}
