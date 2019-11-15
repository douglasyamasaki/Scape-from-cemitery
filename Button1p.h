#pragma once
#include "ButtonBase.h"
namespace MenuButtons {
	class Button1p : public ButtonBase {
	private:
	public:
		void executar();
		Button1p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref);
	};
}