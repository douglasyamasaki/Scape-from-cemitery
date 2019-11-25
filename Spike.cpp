#include "Spike.h"

Spike::Spike(sf::Vector2f pos) : Obstacle(sf::Vector2f(287, 62), pos)
{
	setOrigin(getSize() / 2.0f);
	texture = SpikeModel::getInstance();
	setTexture(texture->getSpike());
}

Spike::~Spike()
{
	texture = nullptr;
}
