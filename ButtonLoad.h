#pragma once
#include "ButtonBase.h"
namespace MenuButtons {
	class ButtonLoad : public ButtonBase {
	private:
	public:
		void executar();
		ButtonLoad(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref);
	};
}