#include "Button2p.h"
using namespace MenuButtons;
#include "MenuHandler.h"
#include "Principal.h"
void MenuButtons::Button2p::executar()
{
	mref->getMhref()->getPrincipal()->setP2on(true);
	mref->getMhref()->switchTonmenu();
	mref->getMhref()->turnOn();
}

MenuButtons::Button2p::Button2p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getP2());
}
