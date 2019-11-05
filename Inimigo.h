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
	void OnCollision(sf::Vector2f direction)
	{
		if (direction.x < 0.0f) {
			speed.x = 0.0f;
		}
		else if (direction.x > 0.0f)
			speed.x = 0.0f;
		if (direction.y < 0.0f) {
			speed.y = 0.0f;
		}
		else if (direction.y > 0.0f) {
			speed.y = 0.0f;
		}
	}

	virtual void update(float deltat) = 0;
	virtual void seek() = 0;
};

