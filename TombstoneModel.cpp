#include "TombstoneModel.h"
using namespace Models;
TombstoneModel* TombstoneModel::instance = 0;

TombstoneModel* TombstoneModel::getInstance() {
	if (instance == nullptr)
		instance = new TombstoneModel();
	return instance;
}
TombstoneModel::TombstoneModel() {
	Tombstone = new sf::Texture;
	Tombstone->loadFromFile("./Sprites/Obstacles/Tombstone.png");
}
TombstoneModel::~TombstoneModel()
{
	delete instance;
	delete Tombstone;
}
