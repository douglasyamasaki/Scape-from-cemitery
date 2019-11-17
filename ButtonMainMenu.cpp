#include "ButtonMainMenu.h"
#include "MenuHandler.h"
#include "Principal.h"
using namespace MenuButtons;

void MenuButtons::ButtonMainMenu::executar()
{
	mref->getMhref()->getPrincipal()->clearcurrentlevel();
	mref->getMhref()->switchTommenu();
	mref->getMhref()->turnOn();
}

MenuButtons::ButtonMainMenu::ButtonMainMenu(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getMainMenu());
}
