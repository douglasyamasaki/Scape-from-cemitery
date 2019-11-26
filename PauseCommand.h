#pragma once
#include "Controller.h"
namespace CompController{
class PauseCommand : public Controller
	{
	public:
		void setMenuHandler(MenuHandler* mhref) { this->mref = mhref; }
		PauseCommand() : Controller() { active = false; }
		PauseCommand(){ active = true; }
		void executar(sf::Event* e);
	};
}

