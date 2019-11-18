#include "Tombstone.h"
int Tombstone::quantity = 0;

Tombstone::Tombstone(sf::Vector2f size, sf::Vector2f pos) : Obstacle (size,pos)
{
	quantity++;
	texture = TombstoneModel::getInstance();
	int rnd = rand() % 100;
	if (rnd < 50){
		setTexture(texture->getTombstone1());
		type = 1;
	}
	else{
		setTexture(texture->getTombstone2());
		type = 2;
	}
	setOrigin(getSize() / 2.0f);
}

Tombstone::~Tombstone()
{
	texture = nullptr;
	quantity--;
}
