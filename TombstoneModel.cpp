#include "TombstoneModel.h"
using namespace Models;
TombstoneModel* TombstoneModel::instance = 0;

TombstoneModel* TombstoneModel::getInstance() {
	if (instance == nullptr)
		instance = new TombstoneModel();
	return instance;
}
TombstoneModel::TombstoneModel() {
	Tombstone1 = new sf::Texture;
	Tombstone2 = new sf::Texture;
	Tombstone1->loadFromFile("./Sprites/Obstacles/Tombstone1.png");
	Tombstone2->loadFromFile("./Sprites/Obstacles/Tombstone2.png");
}
TombstoneModel::~TombstoneModel()
{
	delete instance;
	delete Tombstone1;
	delete Tombstone2;
}
