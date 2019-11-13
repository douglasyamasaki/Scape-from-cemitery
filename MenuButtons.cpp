#include "MenuButtons.h"
#include "MenuHandler.h"
#include "Principal.h"
void MenuButtons::ButtonResume::run()
{
	mref->getMhref()->turnOff();
}

MenuButtons::ButtonResume::ButtonResume(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getResume());
}

void MenuButtons::Button1p::run()
{
	mref->getMhref()->switchTosmenu();
	mref->getMhref()->turnOn();
}

MenuButtons::Button1p::Button1p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getP1());
}

void MenuButtons::Button2p::run()
{
	//falta turnar p2
	mref->getMhref()->switchTosmenu();
	mref->getMhref()->turnOn();
}

MenuButtons::Button2p::Button2p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getP2());
}

void MenuButtons::ButtonBossStage::run()
{
	mref->getMhref()->turnOff();
	mref->getMhref()->switchTopmenu();
	//iniciar o level
}

MenuButtons::ButtonBossStage::ButtonBossStage(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase (size,pos,mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getBossStage());
}

void MenuButtons::ButtonSave::run()
{
	//logica de salvar nivel
}

MenuButtons::ButtonSave::ButtonSave(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getSave());
}

void MenuButtons::ButtonStage1::run()
{
	mref->getMhref()->turnOff();
	mref->getMhref()->switchTopmenu();
	mref->getMhref()->getPrincipal()->startDefaultLevel(1);
	//iniciar o level
}

MenuButtons::ButtonStage1::ButtonStage1(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getStage1());
}

void MenuButtons::ButtonQuit::run()
{
	mref->getMhref()->getPrincipal()->getWindow()->close();
}

MenuButtons::ButtonQuit::ButtonQuit(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getQuit());
}

void MenuButtons::ButtonMainMenu::run()
{
	mref->getMhref()->switchTommenu();
	mref->getMhref()->turnOn();
}

MenuButtons::ButtonMainMenu::ButtonMainMenu(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getMainMenu());
}

void MenuButtons::ButtonLoad::run()
{
	// logica de carregar fase
}

MenuButtons::ButtonLoad::ButtonLoad(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getLoad());
}

void MenuButtons::ButtonHighscore::run()
{
	mref->getMhref()->switchTormenu();
	mref->getMhref()->turnOn();
}

MenuButtons::ButtonHighscore::ButtonHighscore(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getHighscore());
}
