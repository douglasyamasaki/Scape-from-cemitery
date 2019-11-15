#include "MenuSelection.h"
#include "ButtonFirstStage.h"
#include "ButtonBossStage.h"
using namespace MenuButtons;

Menus::MenuSelection::MenuSelection(sf::Vector2f size, MenuHandler* MHref) : MenuBase(size, MHref)
{
	setTexture(texture->getSelection());
	ButtonFirstStage* bs1 = new ButtonFirstStage(sf::Vector2f(244, 57), sf::Vector2f(255, 390), this);
	ButtonBossStage* bbs = new ButtonBossStage(sf::Vector2f(244, 57), sf::Vector2f(835, 390), this);
	add(bs1);
	add(bbs);
}

void Menus::MenuSelection::executar()
{
	drawMenu();
}
