#pragma once
#include "ButtonBase.h"
namespace MenuButtons {
	class ButtonFirstStage : public ButtonBase {
	private:
	public:
		void executar();
		ButtonFirstStage(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref);
		~ButtonFirstStage(){delete(instance);}
	};
}
