#pragma once
#include "AbstractEntitys.h"
using namespace AbstractEntitys;

class ButtonModels;
class Menu;
class MenuButtonBase : public Entity {
private:
	ButtonModels* textures;
	Menu* ref;
public:
	MenuButtonBase(sf::Vector2f size, sf::Vector2f pos, Menu* ref) : Entity(size, pos) { this->ref = ref; }
	virtual void executar() = 0;
};