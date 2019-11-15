#pragma once
#include "MenuBase.h"
namespace Menus {
	class MenuLose : public MenuBase {
	protected:
	public:
		MenuLose(sf::Vector2f size, MenuHandler* MHref);
		void executar();
	};
}