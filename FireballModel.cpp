#include "FireballModel.h"

FireballModel::FireballModel()
{
	Fireball = new sf::Texture;
	Fireball->loadFromFile("./Sprites/Enemies/Dragon/Fireball.png");
}

FireballModel* FireballModel::getInstance()
{
	if (instance == nullptr)
		instance = new FireballModel;
	return instance;
}

FireballModel* FireballModel::instance = 0;
