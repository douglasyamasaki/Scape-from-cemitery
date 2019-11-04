#pragma once
#include "Menus.h"
using namespace Menus;

class Principal;

class MenuHandler
{
private:
	Principal* principalref;
	MenuBase* currentMenu;
	MainMenu mmenu;

public:
	MenuHandler(Principal* principalref);
	Principal* getPrincipal() const { return principalref; }
	bool getActive() const { return currentMenu->getActive(); }
	void input(sf::Vector2f input) { if (currentMenu->getActive()) currentMenu->input(input); }
	void update();
};

