#pragma once
#include "SFML/Graphics.hpp"
#include "Collisor.h"
namespace AbstractEntitys {
	class Entity : public sf::RectangleShape {
	public:
		Entity(sf::Vector2f size,sf::Vector2f pos) : sf::RectangleShape(size) {
			setOrigin(size/2.0f);
			setPosition(pos);
		}

	};

	class StaticEntity : public Entity, public Collisor {
	public:
		StaticEntity(sf::Vector2f size, sf::Vector2f pos) : Entity(size, pos), Collisor(size) { 
			hitbox.setPosition(pos);
		}
	};
	class DynamicEntity : public Entity, public Collisor {
	protected:
		float speed;
	public:
		DynamicEntity(sf::Vector2f size, sf::Vector2f pos, float speed, sf::Vector2f hitbox) : Entity(size, pos), Collisor(hitbox) 
		{ this->speed = speed; }
		DynamicEntity(sf::Vector2f size, sf::Vector2f pos, float speed, sf::Vector2f hitbox,sf::Vector2f deslocamento) : Entity(size, pos), 
		Collisor(hitbox,deslocamento,pos) 
		{ this->speed = speed; }
		
		virtual void update(float deltat) = 0;
	};
}
