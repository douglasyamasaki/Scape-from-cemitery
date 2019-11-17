#pragma once
#include "MenuBase.h"
namespace Menus {
	class MenuMain : public MenuBase {
	protected:
	public:
		MenuMain(sf::Vector2f size, MenuHandler* MHref);
		void executar(sf::Event* event);
	};
}