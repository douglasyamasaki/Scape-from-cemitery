#pragma once
#include "ButtonBase.h"
namespace MenuButtons {
	class ButtonBossStage : public ButtonBase {
	private:
	public:
		void executar();
		ButtonBossStage(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref);
		~ButtonBossStage(){delete(instance);}
	};
}
