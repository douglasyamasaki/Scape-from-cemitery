#pragma once
#include "MenuBase.h"

namespace Menus {
	class LoseMenu : public MenuBase {
	private:
	public:
		LoseMenu(sf::Vector2f size, MenuHandler* MHref);
	};

	class WinMenu : public MenuBase {
	private:
	public:
		WinMenu(sf::Vector2f size, MenuHandler* MHref);
	};

	class SelecaoMenu : public MenuBase {
	private:
	public:
		SelecaoMenu(sf::Vector2f size, MenuHandler* MHref);
	};
	class RankingMenu : public MenuBase {
	private:
	public:
		RankingMenu(sf::Vector2f size, MenuHandler* MHref);
	};
	class MainMenu : public MenuBase {
	private:
	public:
		MainMenu(sf::Vector2f size, MenuHandler* MHref);
	};
	class PauseMenu : public MenuBase {
	private:
	public:
		PauseMenu(sf::Vector2f size, MenuHandler* MHref);
	};
}

