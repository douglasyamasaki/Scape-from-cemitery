#include "MenuNaming.h"
#include "MenuHandler.h"
#include "Principal.h"
using namespace Menus;
MenuNaming::MenuNaming(sf::Vector2f size, MenuHandler* MHref) : MenuBase (size,MHref)
{
	texture = MenuModel::getInstance();
	setTexture(texture->getNaming());
	font.loadFromFile("./Font/ranking.ttf");
	text.setFont(font);
	text.setCharacterSize(30);
	p1l.setFont(font);
	p2l.setFont(font);
	p1l.setString(line);
	p1l.setPosition(sf::Vector2f(460, 260));
	p1l.setCharacterSize(30);

	p2l.setCharacterSize(30);
	p2l.setPosition(sf::Vector2f(150, 300));
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
	text.setPosition(sf::Vector2f(460, 260 + 280 * playerselect));
	printf("%d", playerselect);
	drawMenu();
	if (!MHref->getPrincipal()->getHasP2()) {
		sf::RectangleShape hidep2(sf::Vector2f(460, 265));
		hidep2.setFillColor(sf::Color::Color(26, 17, 17, 255));
		hidep2.setPosition(420, 365);
		MHref->getPrincipal()->getWindow()->draw(hidep2);
	}
	MHref->getPrincipal()->getWindow()->draw(p1l);
	MHref->getPrincipal()->getWindow()->draw(p2l);
	MHref->getPrincipal()->getWindow()->draw(text);
	
}

void MenuNaming::confirm()
{
	if (!MHref->getPrincipal()->getHasP2()) {
		MHref->switchTosmenu();
		MHref->turnOn();
		line.clear();
		p1l.setString(line);
		p2l.setString(line);
		playerselect = 0;
	}
	if (MHref->getPrincipal()->getHasP2() && playerselect == 1) {
		playerselect = 0;
		p2l.setString(line);
		MHref->getPrincipal()->setName(2, line);
		MHref->switchTosmenu();
		MHref->turnOn();
		line.clear();
		p1l.setString(line);
		p2l.setString(line);
		playerselect = 0;
		return;
	}
	if (playerselect == 0) {
		playerselect++;
		MHref->getPrincipal()->setName(1, line);
		p1l.setString(line);
		line.clear();
		return;
	}
}
