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
public:
	MenuBase(sf::Vector2f size, MenuHandler* MHref) : Entity(size) { 
		this->MHref = MHref;
		texture = MenuModel::getInstance();
	}
	void drawMenu();
	MenuHandler* getMhref() { return MHref; }
	void add(MenuButtonBase* element) { buttons.push_back(element); }
	void on() { active = true; }
	void off() { active = false; }
	const bool getActive() const { return active; }
	void input(sf::Vector2f cinput);
	virtual void executar() = 0;
};

