#pragma once
#include "Obstacle.h"
#include "MineModel.h"
using namespace Models;
using namespace AbstractEntity;
class Mine : public Obstacle
{
private:
	MineModel* texture;
public:
	Mine(sf::Vector2f pos);
	~Mine();
};

