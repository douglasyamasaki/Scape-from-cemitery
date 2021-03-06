#include "MenuLose.h"
#include <iostream>
#include "Principal.h"
#include "MenuHandler.h"
using namespace std;
using namespace Menus;
#include "ButtonMainMenu.h"
using namespace MenuButtons;

MenuLose::MenuLose(sf::Vector2f size, MenuHandler* MHref) : MenuBase(size, MHref)
{
	setTexture(texture->getLose());
	ButtonMainMenu* bmm = new ButtonMainMenu(sf::Vector2f(244, 57), sf::Vector2f(525, 415), this);
	add(bmm);
}

void MenuLose::executar(sf::Event* event)
{
	drawMenu();
}
