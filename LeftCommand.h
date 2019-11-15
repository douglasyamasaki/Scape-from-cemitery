#pragma once
#include "Controller.h"
namespace CompController{
class LeftCommand : public Controller
	{
	public:
		LeftCommand() : Controller() { }
		void executar(sf::Event* e);
	};
}
