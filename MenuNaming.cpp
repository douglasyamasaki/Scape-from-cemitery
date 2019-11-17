#include "MenuNaming.h"
#include "MenuHandler.h"
#include "Principal.h"
using namespace Menus;
MenuNaming::MenuNaming(sf::Vector2f size, MenuHandler* MHref) : MenuBase (size,MHref)
{
	texture = MenuModel::getInstance();
	setTexture(texture->getMain());
	font.loadFromFile("./Font/ranking.ttf");
	text.setFont(font);
	text.setCharacterSize(30);
	line = "p1 name:";
	p1l.setFont(font);
	p2l.setFont(font);
	p1l.setString(line);
	p1l.setPosition(sf::Vector2f(150, 150));
	line = "p2 name:";
	p2l.setCharacterSize(30);
	p2l.setCharacterSize(30);
	p1l.setPosition(sf::Vector2f(150, 300));
	p2l.setString(line);
	line.clear();
	playerselect = 0;
}

void MenuNaming::executar(sf::Event* event)
{
	if (event != nullptr)
		if (event->type == sf::Event::TextEntered) {
			line += event->text.unicode;
			text.setString(line);
		}
	text.setPosition(sf::Vector2f(200, 150 + 150 * playerselect));
	drawMenu();
	MHref->getPrincipal()->getWindow()->draw(p1l);
	MHref->getPrincipal()->getWindow()->draw(p2l);
	MHref->getPrincipal()->getWindow()->draw(text);
}

void MenuNaming::confirm()
{
	if (playerselect == 0) {
		playerselect++;
		MHref->getPrincipal()->setName(1, line);
		line.clear();
	}
	if (!MHref->getPrincipal()->getHasP2()) {
		MHref->switchTosmenu();
		MHref->turnOn();
		line.clear();
	}
	if (MHref->getPrincipal()->getHasP2() && playerselect == 1) {
		playerselect = 0;
		MHref->getPrincipal()->setName(2, line);
		MHref->switchTosmenu();
		MHref->turnOn();
		line.clear();
	}
}
