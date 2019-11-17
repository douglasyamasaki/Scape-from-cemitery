#pragma once
#include "MenuBase.h"
namespace Menus {
	class MenuLose : public MenuBase {
	protected:
		sf::Font font;
		string line;
		sf::Text text;
	public:
		MenuLose(sf::Vector2f size, MenuHandler* MHref);
		void executar(sf::Event* event);
	};
}