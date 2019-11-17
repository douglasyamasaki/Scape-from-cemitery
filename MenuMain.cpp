#include "MenuMain.h"
#include "Button1p.h"
#include "Button2p.h"
#include "ButtonLoad.h"
#include "ButtonHighscore.h"
#include "ButtonQuit.h"
using namespace MenuButtons;

Menus::MenuMain::MenuMain(sf::Vector2f size, MenuHandler* MHref) : MenuBase(size, MHref)
{
	setTexture(texture->getMain());
	Button1p* b1p = new Button1p(sf::Vector2f(183, 57), sf::Vector2f(818, 340), this);
	Button2p* b2p = new Button2p(sf::Vector2f(183, 57), sf::Vector2f(1048, 340), this);
	ButtonLoad* bl = new ButtonLoad(sf::Vector2f(244, 57), sf::Vector2f(915, 430), this);
	ButtonHighscore* bhs = new ButtonHighscore(sf::Vector2f(244, 57), sf::Vector2f(915, 525), this);
	ButtonQuit* bq = new ButtonQuit(sf::Vector2f(244, 57), sf::Vector2f(915, 610), this);
	add(b1p);
	add(b2p);
	add(bl);
	add(bhs);
	add(bq);
}

void Menus::MenuMain::executar(sf::Event* event)
{
	drawMenu();
}
