#pragma once
#include "DynamicEntity.h"
namespace AbstractEntity{
	class Projectile : public DynamicEntity{
	private:
	public:
		Projectile(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento) :
		DynamicEntity(size, pos, speed, hitbox, deslocamento) {

		}
		virtual void update(float deltat) = 0;
	};
}