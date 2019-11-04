#pragma once
#include "MenuBase.h"


namespace Menus {
	class LoseMenu : public MenuBase {
	protected:
	public:
		LoseMenu(sf::Vector2f size, MenuHandler* MHref);
		void executar();
	};

	class WinMenu : public MenuBase {
	protected:
	public:
		WinMenu(sf::Vector2f size, MenuHandler* MHref);
		void executar();
	};

	class SelecaoMenu : public MenuBase {
	protected:
	public:
		SelecaoMenu(sf::Vector2f size, MenuHandler* MHref);
		void executar();
	};
	class RankingMenu : public MenuBase {
	protected:
	public:
		RankingMenu(sf::Vector2f size, MenuHandler* MHref);
		void executar();
	};
	class MainMenu : public MenuBase {
	protected:
	public:
		MainMenu(sf::Vector2f size, MenuHandler* MHref);
		void executar();
	};
	class PauseMenu : public MenuBase {
	protected:
	public:
		PauseMenu(sf::Vector2f size, MenuHandler* MHref);
		void executar();
	};
}

