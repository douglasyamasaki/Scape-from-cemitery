#include "GhostModel.h"
using namespace Models;

GhostModel* GhostModel::instance = 0;

GhostModel* GhostModel::getInstance() {
	if (!instance) {
		instance = new GhostModel();
	}
	return instance;
}

GhostModel::GhostModel() {
	Ghost = new sf::Texture();
	Ghost->loadFromFile("./Sprites/Enemies/Ghost/Ghost.png");
}
