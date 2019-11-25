#include "LevelStateHandler.h"
#include <fstream>
#include "EnemiesList.h"
#include "ObstacleList.h"
#include "ProjectileList.h"
#include "Spark.h"
#include "Spell.h"
#include "Arrow.h"
#include "Barrage.h"
#include "Flame.h"
#include "Player.h"
#include "Fireball.h"
#include "Mine.h"
#include "Spike.h"
#include "Tombstone.h"
#include "Dragon.h"
#include "Warlock.h"
#include "Ghost.h"

using namespace std;
LevelStateHandler::LevelStateHandler()
{
	projectiles = nullptr;
	enemies = nullptr;
	obstacles = nullptr;
	p1 = nullptr;
	p2 = nullptr;
	leveltype = -1;
	waitedproj = 0;
	waitedobjeticles = 0;
	waitedenemies = 0;
	pls = 1;
}

enum class LevelStateHandler::SaveType {
	ARROW,
	BARRAGE,
	FLAME,
	SPARK,
	FIREBALL,
	MINE,
	SPIKE,
	TOMBSTONE,
	GHOST,
	WARLOCK,
	DRAGON
};

void LevelStateHandler::save()
{
	if (p2 != nullptr)
		pls = 2;
	ofstream file("./Save/Base.txt", ios::out);

	if (projectiles != nullptr && enemies != nullptr && obstacles != nullptr) {
		file << leveltype << endl;
		file << projectiles->getSize() <<endl;
		file << enemies->getSize() << endl;
		file << obstacles->getSize()<<endl;
		file << pls << endl;
	}
	file.close();
	// salva p1
	file.open("./Save/P1.txt", ios::out);
	if (p1 != nullptr) {
		file << p1->getName() << endl;
		file << p1->getPoints() << endl;
		file << p1->getLives() << endl;
		file << p1->getAttackType() << endl;
		file << p1->getHBPos().x << endl;
		file << p1->getHBPos().y << endl;
		file << p1->getVelocity().x << endl;
		file << p1->getVelocity().y << endl;
		file << p1->getLock() << endl;
		file << p1->getFrame() << endl;
		file << p1->getimgI().x << endl;
		file << p1->getimgI().y << endl;
		file << p1->getInvulneravel() << endl;
		file << p1->getFaceright() << endl;
	}
	file.close();
	//salva p2
	file.open("./Save/P2.txt", ios::out);
	if (p2 != nullptr) {
		file << p2->getName() << endl;
		file << p2->getPoints() << endl;
		file << p2->getLives() << endl;
		file << p2->getAttackType() << endl;
		file << p2->getHBPos().x << endl;
		file << p2->getHBPos().y << endl;
		file << p2->getVelocity().x << endl;
		file << p2->getVelocity().y << endl;
		file << p2->getLock() << endl;
		file << p2->getFrame() << endl;
		file << p2->getimgI().x << endl;
		file << p2->getimgI().y << endl;
		file << p2->getInvulneravel() << endl;
		file << p2->getFaceright() << endl;
	}
	file.close();

	file.open("./Save/Projectiles.txt", ios::out);
	//salva projeteis
	for (projectiles->it = projectiles->getPrimeiro(); projectiles->it != nullptr; projectiles->it++) {
		Arrow* arrowptr = dynamic_cast<Arrow*>(projectiles->it.getIt()->getInfo());
		if (arrowptr != nullptr) {
			file << static_cast<int>(SaveType::ARROW) << endl;
			file << projectiles->it.getIt()->getInfo()->getHBPos().x << endl;
			file << projectiles->it.getIt()->getInfo()->getHBPos().y << endl;
			file << arrowptr->getVelocity().x << endl;
			file << arrowptr->getVelocity().y << endl;
			file << projectiles->it.getIt()->getInfo()->getRotation() << endl;
			if (p1 == arrowptr->getShooter())
				file << 1 << endl;
			else if (p2 == arrowptr->getShooter())
				file << 2 << endl;
			arrowptr = nullptr;
			continue;
		}
		Barrage* barrageptr = dynamic_cast<Barrage*>(projectiles->it.getIt()->getInfo());
		if (barrageptr != nullptr) { 
			file << static_cast<int>(SaveType::BARRAGE) << endl;
			file << barrageptr->getHBPos().x << endl;
			file << barrageptr->getHBPos().y << endl;
			file << barrageptr->getSpeed().x << endl;
			file << barrageptr->getSpeed().y << endl;
			file << barrageptr->getHitable() << endl;
			file << barrageptr->getFrame() << endl;
			file << barrageptr->getimgI().x << endl;
			file << barrageptr->getimgI().y << endl;
			barrageptr = nullptr;
			continue;
		}
		Flame* Flameptr = dynamic_cast<Flame*>(projectiles->it.getIt()->getInfo());
		if (Flameptr != nullptr) {
			file << static_cast<int>(SaveType::FLAME) << endl;
			file << Flameptr->getHBPos().x << endl;
			file << Flameptr->getHBPos().y << endl;
			file << Flameptr->getSpeed().x << endl;
			file << Flameptr->getSpeed().y << endl;
			file << Flameptr->getHitable() << endl;
			file << Flameptr->getFrame() << endl;
			file << Flameptr->getimgI().x << endl;
			file << Flameptr->getimgI().y << endl;
			Flameptr = nullptr;
			continue;
		}
		Spark* Sparkptr = dynamic_cast<Spark*>(projectiles->it.getIt()->getInfo());
		if (Sparkptr != nullptr) {
			file << static_cast<int>(SaveType::SPARK) << endl;
			file << Sparkptr->getHBPos().x << endl;
			file << Sparkptr->getHBPos().y << endl;
			file << Sparkptr->getSpeed().x << endl;
			file << Sparkptr->getSpeed().y << endl;
			file << Sparkptr->getHitable() << endl;
			file << Sparkptr->getFrame() << endl;
			file << Sparkptr->getimgI().x << endl;
			file << Sparkptr->getimgI().y << endl;
			Sparkptr = nullptr;
			continue;
		}
		Fireball* fireballptr = dynamic_cast<Fireball*>(projectiles->it.getIt()->getInfo());
		if (fireballptr != nullptr) {
			file << static_cast<int>(SaveType::FIREBALL) << endl;
			file << fireballptr->getHBPos().x << endl;
			file << fireballptr->getHBPos().y << endl;
			continue;
		}
	}
	file.close();

	file.open("./Save/Obstacles.txt", ios::out);
	for (obstacles->it = obstacles->getPrimeiro(); obstacles->it != nullptr; obstacles->it++) {
		Mine* mineptr = dynamic_cast<Mine*>(obstacles->it.getIt()->getInfo());
		if (mineptr != nullptr) {
			file << static_cast<int>(SaveType::MINE) << endl;
			file << mineptr->getHBPos().x << endl;
			file << mineptr->getHBPos().y << endl;
			continue;
		}
		Spike* spikeptr = dynamic_cast<Spike*>(obstacles->it.getIt()->getInfo());
		if (spikeptr != nullptr) {
			file << static_cast<int>(SaveType::SPIKE) << endl;
			file << spikeptr->getHBPos().x << endl;
			file << spikeptr->getHBPos().y << endl;
			continue;
		}
		Tombstone* Tombstoneptr = dynamic_cast<Tombstone*>(obstacles->it.getIt()->getInfo());
		if (Tombstoneptr != nullptr) {
			file << static_cast<int>(SaveType::TOMBSTONE) << endl;
			file << Tombstoneptr->getHBPos().x << endl;
			file << Tombstoneptr->getHBPos().y << endl;
			continue;
		}
	}
	file.close();

	file.open("./Save/Enemies.txt", ios::out);
	for (enemies->it = enemies->getPrimeiro(); enemies->it != nullptr; enemies->it++) {
		Dragon* dragonptr = dynamic_cast<Dragon*>(enemies->it.getIt()->getInfo());
		if (dragonptr != nullptr) {
			file << static_cast<int>(SaveType::DRAGON) << endl;
			file << dragonptr->getVidas() << endl;
			file << dragonptr->getHBPos().x << endl;
			file << dragonptr->getHBPos().y << endl;
			file << dragonptr->getFrame() << endl;
			file << dragonptr->getimgI().x << endl;
			file << dragonptr->getimgI().y << endl;
			file << dragonptr->getAccumulator() << endl;
			file << dragonptr->getFaceright() << endl;
			continue;
		}
		Ghost* ghostptr = dynamic_cast<Ghost*>(enemies->it.getIt()->getInfo());
		if (ghostptr != nullptr) {
			file << static_cast<int>(SaveType::GHOST) << endl;
			if (ghostptr->getTarget() == p1)
				file << 1 << endl;
			else if (ghostptr->getTarget() == p2)
				file << 2 << endl;
			file << ghostptr->getHBPos().x << endl;
			file << ghostptr->getHBPos().y << endl;
			file << ghostptr->getMoveDirection().x << endl;
			file << ghostptr->getMoveDirection().y << endl;
			file << ghostptr->getimgI().x << endl;
			file << ghostptr->getimgI().y << endl;
			continue;
		}

		Warlock* wlkptr = dynamic_cast<Warlock*>(enemies->it.getIt()->getInfo());
		if (wlkptr != nullptr) {
			file << static_cast<int>(SaveType::WARLOCK)<<endl;
			file << wlkptr->getVidas() << endl;
			file << wlkptr->getHBPos().x << endl;
			file << wlkptr->getHBPos().y << endl;
			file << wlkptr->getMovDirection().x << endl;
			file << wlkptr->getMovDirection().y << endl;
			printf("%d\n", wlkptr->getAttType());
			file << wlkptr->getAttType() << endl;
			file << wlkptr->getFaceright() << endl;
			file << wlkptr->getFrame() << endl;
			file << wlkptr->getUV().width << endl;
			file << wlkptr->getUV().height << endl;
			file << wlkptr->getimgI().x << endl;
			file << wlkptr->getimgI().y << endl;
			file << wlkptr->getImgC().x << endl;
			file << wlkptr->getImgC().y << endl;
			file << wlkptr->getLock()<<endl;
			continue;
		}
	}
	file.close();

}

void LevelStateHandler::load()
{
	int intaux,intaux2,intaux3,intaux4,intaux5,imgIx,imgIy,imgCx,imgCy,uvx,uvy;
	float floataux, floataux2, floataux3,floataux4,floataux5;
	ifstream file;
	file.open("./Save/Projectiles.txt", ios::in);
	for (int i = 0; i < waitedproj; i++) {
		file >> intaux;
		switch (intaux) {
			case static_cast<int>(SaveType::ARROW) :{
				file >> floataux;
				file >> floataux2;
				file >> floataux3; // velo x
				file >> floataux4;  // velo y
				file >> floataux5; // rotation
				file >> intaux2;
				Arrow* arrowptr = new Arrow(sf::Vector2f(floataux, floataux2), sf::Vector2f(floataux3, floataux4), nullptr);
				arrowptr->setRotation(floataux5);
				if (intaux2 == 1)
					arrowptr->setShooter(p1);
				else if (intaux2 == 2)
					arrowptr->setShooter(p2);
				*projectiles + arrowptr;
			}
				break;
			case static_cast<int>(SaveType::BARRAGE) :{
				file >> floataux; // x
				file >> floataux2;//y
				file >> floataux3; // vx
				file >> floataux4; //vy
				file >> intaux2; // hitable
				file >> intaux3; // frame
				file >> imgIx; //img ix
				file >> imgIy;//img iy
				Barrage* barrageptr = new Barrage(sf::Vector2f(floataux, floataux2));
				barrageptr->setSpeed(sf::Vector2f(floataux3, floataux4));
				barrageptr->setHitable(intaux2);
				barrageptr->setFrame(intaux3);
				barrageptr->setimgI(sf::Vector2u(imgIx, imgIy));
				*projectiles + barrageptr;
			}
			break;
			case static_cast<int>(SaveType::SPARK) : {
				file >> floataux; // x
				file >> floataux2;//y
				file >> floataux3; // vx
				file >> floataux4; //vy
				file >> intaux2; // hitable
				file >> intaux3; // frame
				file >> imgIx; //img ix
				file >> imgIy;//img iy
				Spark* sparkptr = new Spark(sf::Vector2f(floataux, floataux2));
				sparkptr->setSpeed(sf::Vector2f(floataux3, floataux4));
				sparkptr->setHitable(intaux2);
				sparkptr->setFrame(intaux3);
				sparkptr->setimgI(sf::Vector2u(imgIx, imgIy));
				*projectiles + sparkptr;
			}
			break;
			case static_cast<int>(SaveType::FLAME) : {
				file >> floataux; // x
				file >> floataux2;//y
				file >> floataux3; // vx
				file >> floataux4; //vy
				file >> intaux2; // hitable
				file >> intaux3; // frame
				file >> imgIx; //img ix
				file >> imgIy;//img iy
				Flame* flameptr = new Flame(sf::Vector2f(floataux, floataux2));
				flameptr->setSpeed(sf::Vector2f(floataux3, floataux4));
				flameptr->setHitable(intaux2);
				flameptr->setFrame(intaux3);
				flameptr->setimgI(sf::Vector2u(imgIx, imgIy));
				*projectiles + flameptr;
			}
			break;
			case static_cast<int>(SaveType::FIREBALL) : {
				file >> floataux;
				file >> floataux2;
				Fireball* fireballptr = new Fireball(sf::Vector2f(floataux, floataux2));
				*projectiles + fireballptr;
			}
		}
	}
	file.close();

	file.open("./Save/Obstacles.txt", ios::in);
	for (int i = 0; i < waitedobjeticles; i++) {
		file >> intaux;
		switch (intaux) {
			case static_cast<int>(SaveType::MINE) : {
				file >> floataux;
				file >> floataux2;
				Mine* mineptr = new Mine(sf::Vector2f(floataux, floataux2));
				*obstacles + mineptr;
			}
			break;

			case static_cast<int>(SaveType::SPIKE) : {
				file >> floataux;
				file >> floataux2;
				Spike* spikeptr = new Spike(sf::Vector2f(floataux, floataux2));
				*obstacles + spikeptr;
			}
			break;

			case static_cast<int>(SaveType::TOMBSTONE) : {
				file >> floataux;
				file >> floataux2;
				Tombstone* tombstoneptr = new Tombstone(sf::Vector2f(floataux, floataux2));
				*obstacles + tombstoneptr;
			}
			break;
		}
	}
	file.close();
	
	file.open("./Save/Enemies.txt", ios::in);
	for (int i = 0; i < waitedenemies; i++) {
		file >> intaux;
		switch (intaux) {
			case static_cast<int>(SaveType::DRAGON) :{
				file >> intaux; //vidas
				file >> floataux; // x
				file >> floataux2; // y
				file >> intaux2; // frame
				file >> imgIx; 
				file >> imgIy;
				file >> floataux3; // acumulator
				file >> intaux3; // faceright
				Dragon* dragonptr = new Dragon(sf::Vector2f(0, 0));
				dragonptr->setVidas(intaux);
				dragonptr->setPos(sf::Vector2f(floataux, floataux2));
				dragonptr->setFrame(intaux2);
				dragonptr->setimgI(sf::Vector2u(imgIx, imgIy));
				dragonptr->setAccumulator(floataux3);
				dragonptr->setFaceright(intaux3);
				dragonptr->setList(projectiles);
				dragonptr->setP1t(p1);
				dragonptr->setP2t(p2);
				*enemies + dragonptr;
				break;
			}
	
			case static_cast<int>(SaveType::GHOST) : {
				file >> intaux; // referencia a player
				file >> floataux; // x
				file >> floataux2; // y
				file >> floataux3; /// movedirection.x
				file >> floataux4;// movedirection.y
				file >> imgIx;
				file >> imgIy;
				Ghost* ghostptr = new Ghost(sf::Vector2f(0.0f, 0.0f), nullptr);
				if (intaux == 1)
					ghostptr->setTarget(p1);
				else if (intaux2 == 2)
					ghostptr->setTarget(p2);
				ghostptr->setPos(sf::Vector2f(floataux, floataux2));
				ghostptr->setMoveDirection(sf::Vector2f(floataux3, floataux4));
				ghostptr->setimgI(sf::Vector2u(imgIx, imgIy));
				*enemies + ghostptr;
				break;
			}
			
			case static_cast<int>(SaveType::WARLOCK) : {
				file >> intaux; // vidas
				file >> floataux2; //x
				file >> floataux3; // y
				file >> floataux4; //movdirection;
				file >> floataux5; //movdirection;
				file >> intaux2; // attacktype
				file >> intaux3; // faceright;
				file >> intaux4; // frame;
				file >> uvx;
				file >> uvy;
				file >> imgIx;
				file >> imgIy;
				file >> imgCx;
				file >> imgCy;
				file >> intaux5; // lock
				Warlock* wlkptr = new Warlock(sf::Vector2f(0.0f, 0.0f), projectiles);
				wlkptr->setVidas(intaux);
				wlkptr->setPos(sf::Vector2f(floataux2, floataux3));
				wlkptr->setAttType(intaux2);
				wlkptr->setFaceright(intaux3);
				wlkptr->setFrame(intaux4);
				wlkptr->setimgI(sf::Vector2u(imgIx,imgIy));
				wlkptr->setImgC(sf::Vector2u(imgCx, imgCy));
				if (intaux5 == 1)
					wlkptr->setLock();
				wlkptr->setP1(p1);
				wlkptr->setP2(p2);
				wlkptr->setMovDirection(sf::Vector2f(floataux4, floataux5));
				wlkptr->setUV(sf::Vector2i(uvx, uvy));
				wlkptr->loadTexture();
				*enemies + wlkptr;
			}

		}
	}
}
