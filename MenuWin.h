#pragma once
#include "MenuBase.h"
namespace Menus {
	class MenuWin : public MenuBase {
	protected:
	public:
		MenuWin(sf::Vector2f size, MenuHandler* MHref);
		void executar(sf::Event* event);
	};
}