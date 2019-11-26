#pragma once
#include "ButtonBase.h"
namespace MenuButtons {
	class ButtonQuit : public ButtonBase {
	private:
	public:
		void executar();
		ButtonQuit(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref);
		~ButtonQuit(){delete(instance);}
	};
}
