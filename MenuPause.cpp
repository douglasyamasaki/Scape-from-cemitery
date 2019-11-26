#include "MenuPause.h"
#include "ButtonMainMenu.h"
#include "ButtonResume.h"
#include "ButtonSave.h"
using namespace MenuButtons;

Menus::MenuPause::MenuPause(sf::Vector2f size, MenuHandler* MHref) : MenuBase(size, MHref)
{
	setTexture(texture->getPause());
	ButtonMainMenu* bmm = new ButtonMainMenu(sf::Vector2f(244, 57), sf::Vector2f(525, 440), this);
	ButtonResume* br = new ButtonResume(sf::Vector2f(244, 57), sf::Vector2f(525, 220), this);
	ButtonSave* bs = new ButtonSave(sf::Vector2f(244, 57), sf::Vector2f(525, 330), this);
	add(bmm);
	add(br);
	add(bs);
}
Menus::~MenuPause(){
	delete(bmm);
	delete(br);
	delete(bs);

void Menus::MenuPause::executar(sf::Event* event)
{
	drawMenu();
}
