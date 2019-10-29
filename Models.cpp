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
	JumpUp = new sf::Texture();
	JumpDown = new sf::Texture();
	Walk->loadFromFile("./Sprites/Skeleton/Walk.png");
	Idle->loadFromFile("./Sprites/Skeleton/Idle.png");
	JumpUp->loadFromFile("./Sprites/Skeleton/Jump Up.png");
	JumpDown->loadFromFile("./Sprites/Skeleton/Jump Down.png");
}

ArrowModel* ArrowModel::getInstance() {
	if (!instance)
		instance = new ArrowModel();
	return instance;
}

ArrowModel::ArrowModel() {
	Arrow = new sf::texture();
	Arrow->loadFromFile("./Sprites/Skeleton/Arrow.png");
}
