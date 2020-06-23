#pragma once
#include "Controller.h"
namespace CompController{
	class Attack03Command : public Controller
	{
	public:
		Attack03Command() : Controller() {}
		void executar(sf::Event* e);
	};
}

