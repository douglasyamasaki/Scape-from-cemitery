#include "Button1p.h"
#include "MenuHandler.h"
#include "Principal.h"
using namespace MenuButtons;

void MenuButtons::Button1p::executar()
{
	Player* p1 = new Player(sf::Vector2f(250, 200), sf::Vector2f(0, 0), sf::Vector2f(100, 0), sf::Vector2f(101, 131), sf::Vector2f(15, -20), nullptr);
	mref->getMhref()->getPrincipal()->setP1(p1);
	mref->getMhref()->switchTonmenu();
	mref->getMhref()->turnOn();
}

MenuButtons::Button1p::Button1p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getP1());
}
