#include "Mine.h"

Mine::Mine(sf::Vector2f size, sf::Vector2f pos) : Obstacle (size,pos)
{
	setOrigin(getSize() / 2.0f);
	texture = MineModel::getInstance();
	setTexture(texture->getMine());
}

Mine::~Mine()
{
	texture = nullptr;
}
