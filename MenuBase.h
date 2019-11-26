#pragma once
#include "Entity.h"
#include <vector>
#include "MenuModel.h"
using namespace std;
using namespace AbstractEntity;
using namespace Models;

class ButtonBase;
class MenuHandler;
class MenuBase : public Entity
{
protected:
	MenuModel* texture;
	vector<ButtonBase*>buttons;
	bool active;
	MenuHandler* MHref;
public:
	MenuBase(sf::Vector2f size, MenuHandler* MHref) : Entity(size) { 
		this->MHref = MHref;
		texture = MenuModel::getInstance();
	}
	~MenuBase(){delete(this->instance);}
	void drawMenu();
	MenuHandler* getMhref() { return MHref; }
	void add(ButtonBase* element) { buttons.push_back(element); }
	void on() { active = true; }
	void off() { active = false; }
	const bool getActive() const { return active; }
	void input(sf::Vector2f cinput);
	virtual void executar(sf::Event* event) = 0;
};

