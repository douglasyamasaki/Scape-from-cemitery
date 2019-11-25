#include "ArcherModel.h"
using namespace Models;
ArcherModel* ArcherModel::instance = 0;

ArcherModel* ArcherModel::getInstance() {
	if (!instance)
		instance = new ArcherModel();
	return instance;
}

ArcherModel::ArcherModel() {
	Walk = new sf::Texture();
	Idle = new sf::Texture();
	JumpUp = new sf::Texture();
	JumpDown = new sf::Texture();
	Attack01 = new sf::Texture();
	Attack02 = new sf::Texture();
	Attack03 = new sf::Texture();
	Die = new sf::Texture();
	Die->loadFromFile("./Sprites/Skeleton/Die.png");
	Walk->loadFromFile("./Sprites/Skeleton/Walk.png");
	Idle->loadFromFile("./Sprites/Skeleton/Idle.png");
	JumpUp->loadFromFile("./Sprites/Skeleton/Jump Up.png");
	JumpDown->loadFromFile("./Sprites/Skeleton/Jump Down.png");
	Attack01->loadFromFile("./Sprites/Skeleton/Attack01.png");
	Attack02->loadFromFile("./Sprites/Skeleton/Attack02.png");
	Attack03->loadFromFile("./Sprites/Skeleton/Attack03.png");
}