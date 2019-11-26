#pragma once
#include "Controller.h"
namespace CompController{
	class UpCommand : public Controller
	{
	public:
		UpCommand() : Controller() { }
		~UpCommand(){}
		void executar(sf::Event* e);
	};
}
