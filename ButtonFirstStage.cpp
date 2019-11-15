#include "ButtonFirstStage.h"
#include "MenuHandler.h"
using namespace MenuButtons;

void MenuButtons::ButtonFirstStage::executar()
{
	mref->getMhref()->turnOff();
	mref->getMhref()->switchTopmenu();
	//iniciar o level
}

MenuButtons::ButtonFirstStage::ButtonFirstStage(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getBossStage());
}
