#pragma once
#include "Entity.h"
#include "Body.h"

namespace AbstractEntity {
	class DynamicEntity : public Entity, public Body {
	protected:
		sf::Vector2f speed;
		sf::Vector2f movdirection;
	public:
		const sf::Vector2f getSpeed() const { return speed; }
		void setSpeed(const sf::Vector2f speed) { this->speed = speed; }
		DynamicEntity(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox) : Entity(size, pos), Body(hitbox)
		{
			this->speed = speed;
		}
		DynamicEntity(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento) : Entity(size, pos),
			Body(hitbox, deslocamento, pos)
		{
			this->speed = speed;
		}
		~DynamimcEntity(){}
		virtual void setPos (sf::Vector2f pos) {
			hitbox.setPosition(pos);
			setPosition(pos);
		}
		const sf::Vector2f getMovDirection() const { return movdirection; }
		void setMovDirection(const sf::Vector2f movdirection) { this->movdirection = movdirection; }
		virtual void update(float deltat) = 0;
	};
}
