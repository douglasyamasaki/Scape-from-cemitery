#include "Tombstone.h"
int Tombstone::quantity = 0;

Tombstone::Tombstone(sf::Vector2f pos) : Obstacle (sf::Vector2f(50,50),pos)
{
	quantity++;
	texture = TombstoneModel::getInstance();
	setTexture(texture->getTombstone());
	setOrigin(getSize() / 2.0f);
}

Tombstone::~Tombstone()
{
	texture = nullptr;
	quantity--;
}
