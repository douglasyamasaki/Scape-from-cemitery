#pragma once
#include "ButtonBase.h"
namespace MenuButtons {
	class Button2p : public ButtonBase {
	private:
	public:
		void executar();
		Button2p(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref);
		~Button2p(){delete(instance)}
	};
}
