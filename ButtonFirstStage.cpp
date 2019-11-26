#include "ButtonFirstStage.h"
#include "MenuHandler.h"
#include "Principal.h"
using namespace MenuButtons;

void MenuButtons::ButtonFirstStage::executar()
{
	mref->getMhref()->turnOff();
	mref->getMhref()->switchTopmenu();
	mref->getMhref()->getPrincipal()->startDefaultLevel(1);
}

MenuButtons::ButtonFirstStage::ButtonFirstStage(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getStage1());
}
