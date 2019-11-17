#include "Button2p.h"
using namespace MenuButtons;
#include "MenuHandler.h"
#include "Principal.h"
void MenuButtons::Button2p::executar()
{
	Player* p1 = new Player(sf::Vector2f(250, 200), sf::Vector2f(0, 0), sf::Vector2f(100, 0), sf::Vector2f(101, 131), sf::Vector2f(15, -20), nullptr);
	Player* p2 = new Player(sf::Vector2f(250, 200), sf::Vector2f(0, 0), sf::Vector2f(100, 0), sf::Vector2f(101, 131), sf::Vector2f(15, -20), nullptr);
	mref->getMhref()->switchTosmenu();
	mref->getMhref()->turnOn();
	mref->getMhref()->getPrincipal()->setP1(p1);
	mref->getMhref()->getPrincipal()->setP2(p2);
}

MenuButtons::Button2p::Button2p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getP2());
}
