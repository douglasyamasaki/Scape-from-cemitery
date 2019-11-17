#include "MenuWin.h"
#include "ButtonMainMenu.h"
using namespace MenuButtons;

Menus::MenuWin::MenuWin(sf::Vector2f size, MenuHandler* MHref) : MenuBase(size, MHref)
{
	setTexture(texture->getWin());
	ButtonMainMenu* bmm = new ButtonMainMenu(sf::Vector2f(244, 57), sf::Vector2f(525, 415), this);
	add(bmm);
}

void Menus::MenuWin::executar(sf::Event* event)
{
	
	drawMenu();
}
