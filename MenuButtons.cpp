#include "MenuButtons.h"
#include "MenuHandler.h"
#include "Principal.h"
void MenuButtons::ButtonResume::executar()
{
}

MenuButtons::ButtonResume::ButtonResume(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getResume());
}

void MenuButtons::Button1p::executar()
{
	printf("p1\n");
}

MenuButtons::Button1p::Button1p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getP1());
}

void MenuButtons::Button2p::executar()
{
}

MenuButtons::Button2p::Button2p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getP2());
}

void MenuButtons::ButtonBossStage::executar()
{
}

MenuButtons::ButtonBossStage::ButtonBossStage(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase (size,pos,mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getBossStage());
}

void MenuButtons::ButtonSave::executar()
{
}

MenuButtons::ButtonSave::ButtonSave(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getSave());
}

void MenuButtons::ButtonStage1::executar()
{
}

MenuButtons::ButtonStage1::ButtonStage1(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getResume());
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
}

MenuButtons::ButtonMainMenu::ButtonMainMenu(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getMainMenu());
}

void MenuButtons::ButtonLoad::executar()
{
}

MenuButtons::ButtonLoad::ButtonLoad(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getLoad());
}

void MenuButtons::ButtonHighscore::executar()
{
}

MenuButtons::ButtonHighscore::ButtonHighscore(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : MenuButtonBase(size, pos, mref)
{
	textures->ButtonModel::getInstance();
	setTexture(textures->getHighscore());
}
