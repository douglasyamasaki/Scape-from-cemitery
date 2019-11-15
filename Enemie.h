#pragma once
#include "Animation.h"
#include "DynamicEntity.h"
namespace AbstractEntity{
class Enemie : public DynamicEntity, public Animation
{
protected:
	int vidas;
	const int reward;
	sf::Vector2f velocity;

public:
	Enemie(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento, const float reward) :
		DynamicEntity(size, pos, speed, hitbox, deslocamento),
		reward(reward) {}
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
	virtual void onHit(sf::Vector2f direction) = 0;
	const int getReward() const { return reward; }
	virtual void update(float deltat) = 0;
	virtual void seek() = 0;
	const int getVidas() const { return vidas; }
};
}
