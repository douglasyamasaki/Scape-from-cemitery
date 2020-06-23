#include "Mine.h"

Mine::Mine( sf::Vector2f pos) : Obstacle (sf::Vector2f(75,75),pos)
{
	setOrigin(getSize() / 2.0f);
	texture = MineModel::getInstance();
	setTexture(texture->getMine());
}

Mine::~Mine()
{
	texture = nullptr;
}
