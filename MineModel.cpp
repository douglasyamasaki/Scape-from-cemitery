#include "MineModel.h"
using namespace Models;
MineModel* MineModel::instance = 0;

MineModel* MineModel::getInstance() {
	if (!instance)
		instance = new MineModel();
	return instance;
}

MineModel::MineModel() {
	Mine = new sf::Texture();
	Mine->loadFromFile("./Sprites/Obstacles/Mine.png");
}

MineModel::~MineModel() {
	delete(Mine);
	delete(instance);
}
