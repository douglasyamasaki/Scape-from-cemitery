#include "Button1p.h"
#include "MenuHandler.h"
#include "Principal.h"
using namespace MenuButtons;

void MenuButtons::Button1p::executar()
{
	mref->getMhref()->switchTonmenu();
	mref->getMhref()->getPrincipal()->setP2on(false);
	mref->getMhref()->turnOn();
}

MenuButtons::Button1p::Button1p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getP1());
}
