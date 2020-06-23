#pragma once
#include "Controller.h"

namespace CompController{
	class EnterCommand : public Controller
	{
	public:
		EnterCommand() : Controller(){ }
		void setMenuHandler(MenuHandler* mhref) { this->mref = mhref; }
		void executar(sf::Event* e);
	};
}
