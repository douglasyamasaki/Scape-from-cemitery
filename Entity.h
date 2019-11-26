#pragma once
#include "SFML/Graphics.hpp"
namespace AbstractEntity {
	class Entity : public sf::RectangleShape {
	public:
		Entity(sf::Vector2f size, sf::Vector2f pos) : sf::RectangleShape(size) {
			setOrigin(size / 2.0f);
			setPosition(pos);
		}
		Entity(sf::Vector2f size) : sf::RectangleShape(size) {
			setOrigin(sf::Vector2f(0.0f, 0.0f));
		}
		~Entity(){}
	};
}
