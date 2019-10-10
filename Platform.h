#pragma once
#include "AbstractEntitys.h"
using namespace AbstractEntitys;
class Platform : public StaticEntity
{
private:
public:
	Platform(sf::Vector2f size, sf::Vector2f pos) : StaticEntity(size, pos) { setTexture(nullptr); setOrigin(getSize() / 2.0f);}
};

