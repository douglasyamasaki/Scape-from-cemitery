#pragma once
#include "AbstractEntitys.h"
#include "Models.h"
using namespace AbstractEntitys;
using namespace SpriteModels;

class Menu;
class MenuButtonBase : public Entity {
protected:
	ButtonModel* textures;
	Menu* mref;
public:
	MenuButtonBase(sf::Vector2f size, sf::Vector2f pos, Menu* mref) : Entity(size, pos) { this->mref = mref; textures->getInstance(); }
	virtual void executar() = 0;
};