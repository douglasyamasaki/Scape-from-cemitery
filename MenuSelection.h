#pragma once
#include "MenuBase.h"
namespace Menus {
	class MenuSelection : public MenuBase {
	protected:
	public:
		MenuSelection(sf::Vector2f size, MenuHandler* MHref);
		void executar();
	};
}