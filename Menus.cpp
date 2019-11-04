#include "Menus.h"
#include "MenuButtons.h"
#include "MenuHandler.h"
#include "Principal.h"
using namespace MenuButtons;
Menus::LoseMenu::LoseMenu(sf::Vector2f size, MenuHandler* MHref) : MenuBase (size,MHref)
{
	setTexture(texture->getLose());
	ButtonMainMenu* bmm = new ButtonMainMenu(sf::Vector2f(183, 57), sf::Vector2f(525, 415), this);
	add(bmm);
}

void Menus::LoseMenu::executar()
{
	drawMenu();
}

Menus::WinMenu::WinMenu(sf::Vector2f size, MenuHandler* MHref) : MenuBase(size, MHref)
{
	setTexture(texture->getWin());
	ButtonMainMenu* bmm = new ButtonMainMenu(sf::Vector2f(183, 57), sf::Vector2f(525, 415), this);
	add(bmm);
}

void Menus::WinMenu::executar()
{
	drawMenu();
}

Menus::SelecaoMenu::SelecaoMenu(sf::Vector2f size, MenuHandler* MHref ) : MenuBase(size, MHref)
{
	setTexture(texture->getSelection());
	ButtonStage1* bs1 = new ButtonStage1(sf::Vector2f(183, 57), sf::Vector2f(255, 390), this);
	ButtonBossStage* bbs = new ButtonBossStage(sf::Vector2f(183, 57), sf::Vector2f(835, 390), this);
	add(bs1);
	add(bbs);
}

void Menus::SelecaoMenu::executar()
{
	drawMenu();
}

Menus::RankingMenu::RankingMenu(sf::Vector2f size, MenuHandler* MHref ) : MenuBase(size, MHref)
{
	setTexture(texture->getRanking());
	ButtonMainMenu* bmm = new ButtonMainMenu(sf::Vector2f(183, 57), sf::Vector2f(525, 625), this);
	add(bmm);
}

void Menus::RankingMenu::executar()
{
	drawMenu();
}

Menus::MainMenu::MainMenu(sf::Vector2f size, MenuHandler* MHref ) : MenuBase(size, MHref)
{
	setTexture(texture->getMain());
	Button1p* b1p = new Button1p(sf::Vector2f(183, 57), sf::Vector2f(818, 340),this );
	Button2p* b2p = new Button2p(sf::Vector2f(183, 57), sf::Vector2f(1048, 340), this);
	ButtonLoad* bl = new ButtonLoad(sf::Vector2f(183, 57), sf::Vector2f(915, 430), this);
	ButtonHighscore* bhs = new ButtonHighscore(sf::Vector2f(183, 57), sf::Vector2f(915, 525), this);
	ButtonQuit* bq = new ButtonQuit(sf::Vector2f(183, 57), sf::Vector2f(915, 610), this);
	add(b1p);
	add(b2p);
	add(bl);
	add(bhs);
	add(bq);
}


void Menus::MainMenu::executar()
{
	drawMenu();
}



Menus::PauseMenu::PauseMenu(sf::Vector2f size, MenuHandler* MHref ) : MenuBase(size, MHref)
{
	setTexture(texture->getPause());
	ButtonMainMenu* bmm = new ButtonMainMenu(sf::Vector2f(183, 57), sf::Vector2f(525, 440), this);
	ButtonResume* br = new ButtonResume(sf::Vector2f(183, 57), sf::Vector2f(525, 220), this);
	ButtonSave* bs = new ButtonSave(sf::Vector2f(183, 57), sf::Vector2f(525, 330), this);
	add(bmm);
	add(br);
	add(bs);
}

void Menus::PauseMenu::executar()
{
	drawMenu();
}
