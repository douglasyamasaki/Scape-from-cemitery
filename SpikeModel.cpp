#include "SpikeModel.h"
using namespace Models;
SpikeModel* SpikeModel::instance = 0;

SpikeModel* SpikeModel::getInstance() {
	if (!instance)
		instance = new SpikeModel();
	return instance;
}
SpikeModel::~SpikeModel()
{
	delete(instance);
	delete(Spike);
}

SpikeModel::SpikeModel() {
	Spike = new sf::Texture();
	Spike->loadFromFile("./Sprites/Obstacles/Spike.png");
}
