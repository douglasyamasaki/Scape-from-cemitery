#pragma once
#include "ButtonBase.h"
namespace MenuButtons {
	class ButtonSave : public ButtonBase {
	private:
	public:
		void executar();
		ButtonSave(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref);
	};
}