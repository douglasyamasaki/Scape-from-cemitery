#pragma once
#include "ButtonBase.h"
namespace MenuButtons {
	class ButtonResume : public ButtonBase {
	private:
	public:
		void executar();
		ButtonResume(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref);
	};
}