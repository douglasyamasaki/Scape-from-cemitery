#include "Models.h"
using namespace SpriteModels;

ArcherModel* ArcherModel::instance = 0;

ArcherModel* ArcherModel::getInstance(){
	if (!instance)
		instance = new ArcherModel();
	return instance;
}

ArcherModel::ArcherModel() {
	Walk = new sf::Texture();
	Idle = new sf::Texture();
	Walk->loadFromFile("./Sprites/Skeleton/Walk.png");
	Idle->loadFromFile("./Sprites/Skeleton/Idle.png");
}