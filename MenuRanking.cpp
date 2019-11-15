#include "MenuRanking.h"
#include "ButtonMainMenu.h"
using namespace MenuButtons;

Menus::MenuRanking::MenuRanking(sf::Vector2f size, MenuHandler* MHref) : MenuBase(size, MHref)
{
	setTexture(texture->getRanking());
	ButtonMainMenu* bmm = new ButtonMainMenu(sf::Vector2f(244, 57), sf::Vector2f(525, 625), this);
	add(bmm);
}

void Menus::MenuRanking::executar()
{
	drawMenu();
}
