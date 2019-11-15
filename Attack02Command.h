#pragma once
#include "Controller.h"
namespace CompController {
	class Attack02Command : public Controller
	{
	public:
		Attack02Command() : Controller() {}
		void executar(sf::Event* e);
	};
}