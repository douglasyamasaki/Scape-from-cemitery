#include "MenuButtons.h"

void MenuButtons::Button1p::executar()
{
}

MenuButtons::Button1p::Button1p(sf::Vector2f size, sf::Vector2f pos, Menu* mref) : MenuButtonBase(size, pos, mref)
{
	setTexture(textures->getP1());
}

void MenuButtons::Button2p::executar()
{
}

MenuButtons::Button2p::Button2p(sf::Vector2f size, sf::Vector2f pos, Menu* mref) : MenuButtonBase(size, pos, mref)
{
	setTexture(textures->getP2());
}

void MenuButtons::ButtonBossStage::executar()
{
}

MenuButtons::ButtonBossStage::ButtonBossStage(sf::Vector2f size, sf::Vector2f pos, Menu* mref) : MenuButtonBase(size, pos, mref)
{
	setTexture(textures->getBossStage());
}

void MenuButtons::ButtonHighscore::executar()
{
}

MenuButtons::ButtonHighscore::ButtonHighscore(sf::Vector2f size, sf::Vector2f pos, Menu* mref) : MenuButtonBase(size, pos, mref)
{
	setTexture(textures->getHighscore());
}

void MenuButtons::ButtonLoad::executar()
{
}

MenuButtons::ButtonLoad::ButtonLoad(sf::Vector2f size, sf::Vector2f pos, Menu* mref) : MenuButtonBase(size, pos, mref)
{
	setTexture(textures->getLoad());
}

void MenuButtons::ButtonMainMenu::executar()
{
}

MenuButtons::ButtonMainMenu::ButtonMainMenu(sf::Vector2f size, sf::Vector2f pos, Menu* mref) : MenuButtonBase(size, pos, mref)
{
	setTexture(textures->getMainMenu());
}

void MenuButtons::ButtonQuit::executar()
{
}

MenuButtons::ButtonQuit::ButtonQuit(sf::Vector2f size, sf::Vector2f pos, Menu* mref) : MenuButtonBase(size, pos, mref)
{
	setTexture(textures->getQuit());
}

void MenuButtons::ButtonResume::executar()
{
}

MenuButtons::ButtonResume::ButtonResume(sf::Vector2f size, sf::Vector2f pos, Menu* mref) : MenuButtonBase(size, pos, mref)
{
	setTexture(textures->getResume());
}

void MenuButtons::ButtonStage1::executar()
{
}

MenuButtons::ButtonStage1::ButtonStage1(sf::Vector2f size, sf::Vector2f pos, Menu* mref) : MenuButtonBase(size, pos, mref)
{
	setTexture(textures->getStage1());
}

void MenuButtons::ButtonSave::executar()
{
}

MenuButtons::ButtonSave::ButtonSave(sf::Vector2f size, sf::Vector2f pos, Menu* mref) : MenuButtonBase(size, pos, mref)
{
	setTexture(textures->getSave());
}
