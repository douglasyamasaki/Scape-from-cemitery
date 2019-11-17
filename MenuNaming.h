#pragma once
#include "MenuBase.h"
namespace Menus{
class MenuNaming: public MenuBase
	{
	private:
		sf::Text text;
		string line;
		sf::Text p1l;
		sf::Text p2l;
		sf::Font font;
		int playerselect;
	public:
		MenuNaming(sf::Vector2f size, MenuHandler* MHref);
		void executar(sf::Event* event);
		void confirm();
	};
}
