#pragma once
#include "Controller.h"
namespace CompController {
	class RightCommand : public Controller
	{
	public:
		RightCommand() : Controller() { }
		void executar(sf::Event* e);
	};
}
