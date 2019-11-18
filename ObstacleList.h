#pragma once
#include "Obstacle.h"
#include "GenericList.h"
using namespace AbstractEntity;
class ObstacleList : public GenericList<Obstacle>
{
private:
public:
	~ObstacleList() { clean(); }
};

