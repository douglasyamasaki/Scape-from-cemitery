#pragma once
#include "MenuBase.h"
namespace Menus {
	class MenuRanking : public MenuBase {
	protected:
	public:
		MenuRanking(sf::Vector2f size, MenuHandler* MHref);
		void executar();
	};
}