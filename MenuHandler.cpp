#include "MenuHandler.h"
#include "Principal.h"
MenuHandler::MenuHandler(Principal* principalref) :
	mmenu(sf::Vector2f(1280,720),this),
	smenu(sf::Vector2f(1280,720),this),
	wmenu(sf::Vector2f(1280, 720), this),
	lmenu(sf::Vector2f(1280, 720), this),
	pmenu(sf::Vector2f(1280, 720), this),
	rmenu(sf::Vector2f(1280, 720), this)
{
	this->principalref = principalref;
	currentMenu = &mmenu;
	currentMenu->on();
	
}

void MenuHandler::update() {
	getPrincipal()->resetView();
	currentMenu->run();
}
