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
	SelecaoMenu smenu;
	PauseMenu pmenu;
	WinMenu wmenu;
	LoseMenu lmenu;
	RankingMenu rmenu;

public:
	MenuHandler(Principal* principalref);
	Principal* getPrincipal() const { return principalref; }
	void turnOff() { currentMenu->off(); }
	void turnOn() { currentMenu->on(); }
	void switchTosmenu() { currentMenu->off(); currentMenu = &smenu; }
	void switchTopmenu() { currentMenu->off(); currentMenu = &pmenu; }
	void switchTormenu() { currentMenu->off(); currentMenu = &rmenu; }
	void switchTommenu() { currentMenu->off(); currentMenu = &mmenu; }
	MenuBase* getCurrentMenu() { return currentMenu; }
	bool getActive() const { return currentMenu->getActive(); }
	void input(sf::Vector2f input) { if (currentMenu->getActive()) currentMenu->input(input); }
	void update();
};

