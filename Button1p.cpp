#include "Button1p.h"
#include "MenuHandler.h"
using namespace MenuButtons;

void MenuButtons::Button1p::executar()
{
	mref->getMhref()->switchTosmenu();
	mref->getMhref()->turnOn();
}

MenuButtons::Button1p::Button1p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getP1());
}
