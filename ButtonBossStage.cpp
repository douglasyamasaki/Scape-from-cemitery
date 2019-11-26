#include "ButtonBossStage.h"
#include "MenuHandler.h"
#include "Principal.h"
using namespace MenuButtons;
void MenuButtons::ButtonBossStage::executar()
{
	mref->getMhref()->turnOff();
	mref->getMhref()->switchTopmenu();
	mref->getMhref()->getPrincipal()->startDefaultLevel(2);
}

MenuButtons::ButtonBossStage::ButtonBossStage(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getBossStage());
}
