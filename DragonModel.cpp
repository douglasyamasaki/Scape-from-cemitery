#include "DragonModel.h"

DragonModel::DragonModel()
{
	Dragon = new sf::Texture;
	Dragon->loadFromFile("./Sprites/Enemies/Dragon/Dragon.png");
}

DragonModel* DragonModel::getInstance()
{
	if (instance == nullptr)
		instance = new DragonModel();
	return instance;
}

DragonModel* DragonModel::instance = 0;