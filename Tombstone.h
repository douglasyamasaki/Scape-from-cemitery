#pragma once
#include "Obstacle.h"
#include "TombstoneModel.h"
using namespace AbstractEntity;
using namespace Models;

class Tombstone : public Obstacle
{
private:
	static int quantity;
	TombstoneModel* texture;
	int type;
public:
	Tombstone(sf::Vector2f size, sf::Vector2f pos);
	static const int getQuantity()  { return quantity; }
	const int getType() const { return type; }
	~Tombstone();
};

