#pragma once
#include "Obstacle.h"
#include "SpikeModel.h"
using namespace Models;
using namespace AbstractEntity;
class Spike : public Obstacle
{
private:
	SpikeModel* texture;
public:
	Spike(sf::Vector2f pos);
	~Spike();
};

