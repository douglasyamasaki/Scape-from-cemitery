#pragma once
#include "SFML/Graphics.hpp"
namespace AbstractEntitys {
	class Entity : public sf::RectangleShape {
	public:
		Entity(sf::Vector2f size) : sf::RectangleShape(size) {}

	};

	class DynamicEntity : public Entity {
	protected:
		float speed;
	public:
		DynamicEntity(sf::Vector2f size, float speed) : Entity(size) { this->speed = speed; }
		virtual void update(float deltat) = 0;
	};
}
