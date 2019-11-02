#include "Menus.h"
Menus::LoseMenu::LoseMenu(sf::Vector2f size, MenuHandler* MHref) : MenuBase (size,MHref)
{
	setTexture(texture->getLose());
}

Menus::WinMenu::WinMenu(sf::Vector2f size, MenuHandler* MHref) : MenuBase(size, MHref)
{
	setTexture(texture->getWin());
}

Menus::SelecaoMenu::SelecaoMenu(sf::Vector2f size, MenuHandler* MHref ) : MenuBase(size, MHref)
{
	setTexture(texture->getSelection());
}

Menus::RankingMenu::RankingMenu(sf::Vector2f size, MenuHandler* MHref ) : MenuBase(size, MHref)
{
	setTexture(texture->getRanking());
}

Menus::MainMenu::MainMenu(sf::Vector2f size, MenuHandler* MHref ) : MenuBase(size, MHref)
{
	setTexture(texture->getMain());
}

Menus::PauseMenu::PauseMenu(sf::Vector2f size, MenuHandler* MHref ) : MenuBase(size, MHref)
{
	setTexture(texture->getPause());
}
