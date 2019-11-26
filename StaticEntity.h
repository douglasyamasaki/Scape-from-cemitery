#pragma once
#include "Entity.h"

namespace AbstractEntity {
	class StaticEntity : public Entity {
	public:
		StaticEntity(sf::Vector2f size, sf::Vector2f pos) : Entity(size, pos) {
	
		}
		~StaticEntity(){}
	};
}
