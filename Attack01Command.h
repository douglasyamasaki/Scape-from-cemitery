#pragma once
#include "Controller.h"
namespace CompController {
	class Attack01Command : public Controller
	{
	public:
		Attack01Command() : Controller() {}
		void executar(sf::Event* e);
	};
}