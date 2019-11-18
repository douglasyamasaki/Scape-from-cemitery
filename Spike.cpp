#include "Spike.h"

Spike::Spike(sf::Vector2f size, sf::Vector2f pos) : Obstacle(size, pos)
{
	setOrigin(getSize() / 2.0f);
	texture = SpikeModel::getInstance();
	setTexture(texture->getSpike());
}

Spike::~Spike()
{
	texture = nullptr;
}
