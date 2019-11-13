#pragma once
#include "AbstractEntitys.h"
#include "Models.h"
#include "MenuBase.h"
using namespace AbstractEntitys;
using namespace SpriteModels;

class MenuButtonBase : public Entity {
protected:
	ButtonModel* textures;
	MenuBase* mref;
public:
	MenuButtonBase(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : Entity(size) { this->mref = mref; textures = ButtonModel::getInstance(); setPosition(pos); }
	virtual void run() = 0;
};