#include "MenuButtons.h"
#include "MenuHandler.h"
#include "Principal.h"
void MenuButtons::ButtonResume::executar()
{
	mref->getMhref()->turnOff();
}

MenuButtons::ButtonResume::ButtonResume(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getResume());
}

void MenuButtons::Button1p::executar()
{
	mref->getMhref()->switchTosmenu();
	mref->getMhref()->turnOn();
}

MenuButtons::Button1p::Button1p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getP1());
}

void MenuButtons::Button2p::executar()
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

void MenuButtons::ButtonBossStage::executar()
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

void MenuButtons::ButtonSave::executar()
{
	//logica de salvar nivel
}

MenuButtons::ButtonSave::ButtonSave(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getSave());
}

void MenuButtons::ButtonStage1::executar()
{
	mref->getMhref()->turnOff();
	mref->getMhref()->switchTopmenu();
	//iniciar o level
}

MenuButtons::ButtonStage1::ButtonStage1(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getStage1());
}

void MenuButtons::ButtonQuit::executar()
{
	mref->getMhref()->getPrincipal()->getWindow()->close();
}

MenuButtons::ButtonQuit::ButtonQuit(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getQuit());
}

void MenuButtons::ButtonMainMenu::executar()
{
	mref->getMhref()->switchTommenu();
	mref->getMhref()->turnOn();
}

MenuButtons::ButtonMainMenu::ButtonMainMenu(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getMainMenu());
}

void MenuButtons::ButtonLoad::executar()
{
	// logica de carregar fase
}

MenuButtons::ButtonLoad::ButtonLoad(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getLoad());
}

void MenuButtons::ButtonHighscore::executar()
{
	mref->getMhref()->switchTormenu();
	mref->getMhref()->turnOn();
}

MenuButtons::ButtonHighscore::ButtonHighscore(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getHighscore());
}
