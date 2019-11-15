#include "ArrowModel.h"
using namespace Models;
ArrowModel* ArrowModel::instance = 0;

ArrowModel* ArrowModel::getInstance() {
	if (!instance)
		instance = new ArrowModel();
	return instance;
}

ArrowModel::ArrowModel() {
	Arrow = new sf::Texture();
	Arrow->loadFromFile("./Sprites/Skeleton/Arrow.png");
}