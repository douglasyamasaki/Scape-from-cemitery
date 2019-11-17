#include "ButtonHighscore.h"
#include "MenuHandler.h"
#include "MenuRanking.h"
using namespace MenuButtons;

void MenuButtons::ButtonHighscore::executar()
{
	mref->getMhref()->switchTormenu();
	mref->getMhref()->turnOn();
	MenuRanking* menuptr = dynamic_cast<MenuRanking*>(mref->getMhref()->getCurrentMenu());
	if (menuptr != nullptr) {
		menuptr->reset();
		menuptr->read();
	}
	
}

MenuButtons::ButtonHighscore::ButtonHighscore(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getHighscore());
}
