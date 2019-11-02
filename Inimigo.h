#pragma once
#include "Animation.h"
#include "AbstractEntitys.h"
using namespace AbstractEntitys;
class Inimigo : public DynamicEntity, public Animation
{
private:
	int vidas;
	const int reward;

public:
	Inimigo(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento,const float reward) : 
		DynamicEntity(size, pos , speed,hitbox,deslocamento),
		reward(reward){}
	virtual void update() = 0;
	virtual void seek() = 0;
};

