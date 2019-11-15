#pragma once
#include "StaticEntity.h"
#include "Body.h"
using namespace AbstractEntity;
class Platform : public StaticEntity , public Body
{
private:
public:
	Platform(sf::Vector2f size, sf::Vector2f pos) : StaticEntity(size, pos) , Body (size){ setTexture(nullptr); setOrigin(getSize() / 2.0f);}
};

