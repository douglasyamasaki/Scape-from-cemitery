#pragma once
#include "StaticEntity.h"
#include "Body.h"
namespace AbstractEntity {
	class Obstacle : public Entity, public Body {
	private:
	public:
		Obstacle(sf::Vector2f size, sf::Vector2f pos) : Entity (size,pos), Body (size,sf::Vector2f(0.0f,0.0f),pos) { }
		~Obstacle(){}
		virtual ~Obstacle() {}
	};
}
