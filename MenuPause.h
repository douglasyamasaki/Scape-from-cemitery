#pragma once
#include "MenuBase.h"
namespace Menus {
	class MenuPause : public MenuBase {
	protected:
	public:
		MenuPause(sf::Vector2f size, MenuHandler* MHref);
		void executar();
	};
}