#include "ButtonQuit.h"
#include "MenuHandler.h"
#include "Principal.h"
using namespace MenuButtons;

void MenuButtons::ButtonQuit::executar()
{
	mref->getMhref()->getPrincipal()->getWindow()->close();
}

MenuButtons::ButtonQuit::ButtonQuit(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getQuit());
}
