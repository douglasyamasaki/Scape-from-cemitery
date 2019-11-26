#pragma once
#include "Controller.h"
namespace CompController{
	class Attack03Command : public Controller
	{
	public:
		Attack03Command() : Controller() {}
		~Attack03Command(){}
		void executar(sf::Event* e);
	};
}

