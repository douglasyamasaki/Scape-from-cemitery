#pragma once
#include "MenuLose.h"
#include "MenuMain.h"
#include "MenuWin.h"
#include "MenuLose.h"
#include "MenuSelection.h"
#include "MenuPause.h"
#include "MenuRanking.h"
#include "MenuNaming.h"
using namespace Menus;
class Principal;

class MenuHandler
{
private:
	Principal* principalref;
	MenuBase* currentMenu;
	MenuMain mmenu;
	MenuSelection smenu;
	MenuPause pmenu;
	MenuWin wmenu;
	MenuLose lmenu;
	MenuRanking rmenu;
	MenuNaming nmenu;

public:
	MenuHandler(Principal* principalref);
	Principal* getPrincipal() const { return principalref; }
	void turnOff() { currentMenu->off(); }
	void turnOn() { currentMenu->on(); }
	void switchTonmenu() { currentMenu->off(); currentMenu = &nmenu; }
	void switchTosmenu() { currentMenu->off(); currentMenu = &smenu; }
	void switchTopmenu() { currentMenu->off(); currentMenu = &pmenu; }
	void switchTormenu() { currentMenu->off(); currentMenu = &rmenu; }
	void switchTommenu() { currentMenu->off(); currentMenu = &mmenu; }
	void switchTowmenu() { currentMenu->off(); currentMenu = &wmenu; }
	void switchTolmenu() { currentMenu->off(); currentMenu = &lmenu; }
	MenuBase* getCurrentMenu() { return currentMenu; }
	bool getActive() const { return currentMenu->getActive(); }
	void input(sf::Vector2f input) { if (currentMenu->getActive()) currentMenu->input(input); }
	void update(sf::Event* event);
};

