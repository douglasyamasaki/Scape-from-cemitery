#pragma once
#include "ButtonBase.h"
namespace MenuButtons {
	class ButtonHighscore : public ButtonBase {
	private:
	public:
		void executar();
		ButtonHighscore(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref);
		~ButtonHighscore(){delete(instance);}
	};
}
