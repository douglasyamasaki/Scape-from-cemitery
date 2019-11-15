#pragma once
#include "ButtonBase.h"
namespace MenuButtons {
	class ButtonMainMenu : public ButtonBase {
	private:
	public:
		void executar();
		ButtonMainMenu(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref);
	};
}