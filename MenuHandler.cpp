#include "MenuHandler.h"
#include "Principal.h"
MenuHandler::MenuHandler(Principal* principalref) :
	mmenu(sf::Vector2f(1280,720),this)
{
	this->principalref = principalref;
	currentMenu = &mmenu;
	currentMenu->on();
	
}

void MenuHandler::update() {
	currentMenu->executar();
}
