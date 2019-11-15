#include "ButtonResume.h"
using namespace MenuButtons;
#include "MenuHandler.h"

void ButtonResume::executar()
{
	mref->getMhref()->turnOff();
}

MenuButtons::ButtonResume::ButtonResume(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase (size,pos,mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getResume());
}
