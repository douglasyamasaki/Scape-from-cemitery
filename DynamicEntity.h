#pragma once
#include "Entity.h"
#include "Body.h"

namespace AbstractEntity {
	class DynamicEntity : public Entity, public Body {
	protected:
		sf::Vector2f speed;
		sf::Vector2f movdirection;
	public:
		DynamicEntity(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox) : Entity(size, pos), Body(hitbox)
		{
			this->speed = speed;
		}
		DynamicEntity(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento) : Entity(size, pos),
			Body(hitbox, deslocamento, pos)
		{
			this->speed = speed;
		}

		virtual void update(float deltat) = 0;
	};
}
