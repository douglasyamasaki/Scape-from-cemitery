#include "Button2p.h"
using namespace MenuButtons;
#include "MenuHandler.h"
void MenuButtons::Button2p::executar()
{
	//falta turnar p2
	mref->getMhref()->switchTosmenu();
	mref->getMhref()->turnOn();
}

MenuButtons::Button2p::Button2p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getP2());
}
