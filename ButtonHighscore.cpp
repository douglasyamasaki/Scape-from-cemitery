#include "ButtonHighscore.h"
#include "MenuHandler.h"
using namespace MenuButtons;

void MenuButtons::ButtonHighscore::executar()
{
	mref->getMhref()->switchTormenu();
	mref->getMhref()->turnOn();
	//listar ranking
}

MenuButtons::ButtonHighscore::ButtonHighscore(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getHighscore());
}
