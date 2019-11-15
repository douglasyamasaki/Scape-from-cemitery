#include "ButtonBossStage.h"
#include "MenuHandler.h"
using namespace MenuButtons;
void MenuButtons::ButtonBossStage::executar()
{
	mref->getMhref()->turnOff();
	mref->getMhref()->switchTopmenu();
	//iniciar o level
}

MenuButtons::ButtonBossStage::ButtonBossStage(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getBossStage());
}
