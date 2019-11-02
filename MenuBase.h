#pragma once
#include "AbstractEntitys.h"
#include <vector>
#include "Models.h"
using namespace std;
using namespace AbstractEntitys;
using namespace SpriteModels;

class MenuButtonBase;
class MenuHandler;

class MenuBase : public Entity
{
protected:
	MenuModel* texture;
	vector<MenuButtonBase*>buttons;
	bool active;
	MenuHandler* MHref;
	virtual void input(sf::Vector2f cinput) = 0;
	virtual void executar() = 0;
	virtual void drawMenu(sf::RenderWindow* window) = 0;
public:
	MenuBase(sf::Vector2f size, MenuHandler* MHref) : Entity(size) { 
		this->MHref = MHref;
		texture = MenuModel::getInstance();
	}
	void add(MenuButtonBase* element) { buttons.push_back(element); }
	void on() { active = true; }
	void off() { active = false; }
};

