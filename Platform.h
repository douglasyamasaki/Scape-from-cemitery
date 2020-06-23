#pragma once
#include "StaticEntity.h"
#include "Body.h"
using namespace AbstractEntity;
class Platform : public StaticEntity , public Body
{
private:
	sf::Vector2f hbpos;
public:
<<<<<<< HEAD
	Platform(sf::Vector2f size, sf::Vector2f pos) : StaticEntity(size, pos), Body(size) { setTexture(nullptr); setOrigin(getSize() / 2.0f); hitbox.setPosition(pos); hbpos = hitbox.getPosition(); }
	~Plataform(){}
=======
	Platform(sf::Vector2f size, sf::Vector2f pos) : StaticEntity(size, pos), Body(size) { setTexture(nullptr); setOrigin(getSize() / 2.0f); hbpos = hitbox.getPosition(); }
>>>>>>> parent of f7c28ad... Updating
	void fix() { hitbox.setPosition(hbpos); setPosition(hitbox.getPosition()); }
};

