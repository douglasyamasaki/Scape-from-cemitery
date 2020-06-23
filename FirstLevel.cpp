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
#include "TilesetModel.h"
void FirstLevel::resetlists()
{
	obstaclesapoints.clear();
	obstaclesapoints.push_back(sf::Vector2f(-2025, 809 + 37));
	obstaclesapoints.push_back(sf::Vector2f(-1750, 809 + 37));
	obstaclesapoints.push_back(sf::Vector2f(-1295, 638 + 37));
	obstaclesapoints.push_back(sf::Vector2f(-800, 558 + 37));
	obstaclesapoints.push_back(sf::Vector2f(-293, 478 + 37));
	obstaclesapoints.push_back(sf::Vector2f(193, 314 + 37));
	obstaclesapoints.push_back(sf::Vector2f(2295, 809 + 37));
	obstaclesbpoints.push_back(sf::Vector2f(147.78, 809 + 32));
	obstaclesbpoints.clear();
	obstaclesbpoints.push_back(sf::Vector2f(500, 314 + 32));
	obstaclesbpoints.push_back(sf::Vector2f(690, 314 + 32));
	obstaclesbpoints.push_back(sf::Vector2f(1003, 314 + 32));
	obstaclesbpoints.push_back(sf::Vector2f(-1500, 809 + 32));
	obstaclesbpoints.push_back(sf::Vector2f(1777, 809 + 32));
	obstaclesbpoints.push_back(sf::Vector2f(2316, 809 + 32));
	obstaclesbpoints.push_back(sf::Vector2f(3065, 809 + 32));
	obstaclesbpoints.push_back(sf::Vector2f(2747, 809 + 32));

	enemiespoints.clear();
	enemiespoints.push_back(sf::Vector2f(-293, 478 + 32));
	enemiespoints.push_back(sf::Vector2f(-800, 558 + 32));
	enemiespoints.push_back(sf::Vector2f(-1295, 638 + 32));
	enemiespoints.push_back(sf::Vector2f(614, 314 + 32));
	enemiespoints.push_back(sf::Vector2f(1752, 809 + 32));
	enemiespoints.push_back(sf::Vector2f(2254, 809 + 32));
	enemiespoints.push_back(sf::Vector2f(2571, 809 + 32));
	enemiespoints.push_back(sf::Vector2f(3127, 809 + 32));
}
FirstLevel::FirstLevel() : Level()
{
	// lista de possiveis spawns
	resetlists();
	
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

	TilesetModel* instance = TilesetModel::getInstance();
	Platform* chao = new Platform(sf::Vector2f(10000, 250), sf::Vector2f(-1000, 1000));
	Platform* chao2 = new Platform(sf::Vector2f(300, 50),sf::Vector2f(-1300, 729));
	Platform* chao3 = new Platform(sf::Vector2f(300, 50), sf::Vector2f(-800, 649));
	Platform* chao4 = new Platform(sf::Vector2f(300, 50), sf::Vector2f(-300, 569));
	Platform* chao5 = new Platform(sf::Vector2f(1200, 500), sf::Vector2f(620, 630));
	Platform* invisible = new Platform(sf::Vector2f(100, 5000), sf::Vector2f(-2400, 809));
	invisible->setFillColor(sf::Color::Transparent);
	platforms + invisible;
	instance->getTile1()->setRepeated(true);
	chao->setTexture(instance->getTile1());
	chao2->setTexture(instance->getTile1());
	chao3->setTexture(instance->getTile1());
	chao4->setTexture(instance->getTile1());
	chao5->setTexture(instance->getTile1());
	chao->setTextureRect(sf::IntRect(0, 0, 10000, 125));
	chao2->setTextureRect(sf::IntRect(0, 0, 300, 125));
	chao3->setTextureRect(sf::IntRect(0, 0, 300, 125));
	chao4->setTextureRect(sf::IntRect(0, 0, 300, 125));
	chao5->setTextureRect(sf::IntRect(0, 0, 1200, 125));
	platforms + chao2;
	platforms + chao3;
	platforms + chao;
	platforms + chao4;
	platforms + chao5;
	lvlstateh.setType(1);
}


void FirstLevel::load_default() {
	load_static();
	p1->setList(&projectiles);
	if (p2 != nullptr){
		p2->setList(&projectiles);
		collider.setP2r(p2);
		p2->setPos(sf::Vector2f(-2253, 809));
	}
	srand(time(nullptr));
	int j = rand() % 3;
	j += 5;
	list<sf::Vector2f>::iterator it;
	
	while (j > 0) {
		it = enemiespoints.begin();
		Dragon* dragonptr = new Dragon(*it);
		enemiespoints.pop_front();
		dragonptr->setList(&projectiles);
		dragonptr->setP1t(p1);
		dragonptr->setP2t(p2);
		enemies + dragonptr;
		j--;
	}
	j = rand() % 3;
	j += 5;
	while (j > 0) {
		it = obstaclesapoints.begin();
		Mine* mineptr = new Mine(*it);
		obstaclesapoints.pop_front();
		obstacles + mineptr;
		j--;
	}
	j = rand() % 3;
	j += 5;
	while (j > 0) {
		it = obstaclesbpoints.begin();
		Spike* spikeptr = new Spike(*it);
		obstaclesbpoints.pop_front();
		obstacles + spikeptr;
		j--;
	}

	ghostqty = rand() % 6;
	ghostqty += 5;
	for (int i = 0; i < ghostqty; i++) {
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
		else{
			ghstptr->setTarget(p1);
		}
		enemies + ghstptr;
	}
	p1->setPos(sf::Vector2f(-2253, 809));
	lvlstateh.setP1(p1);
	collider.setP1r(p1);
	lvlstateh.setGhostQuantity(ghostqty);
	resetlists();
	
}

void FirstLevel::update(float deltat)
{
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
	if (p1->getPosition().x > 3600)
		finished = true;
}
