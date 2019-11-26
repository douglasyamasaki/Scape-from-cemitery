#pragma once
#include "Controller.h"
#include <map>
using namespace std;

namespace CompController {
	class CompositeController : public Controller
	{
	private:
		map<sf::Keyboard::Key, Controller*> cmdMap;
	public:
		void setRef(Player* ref);
		CompositeController() : Controller() { active = false; }
		void add(sf::Keyboard::Key key, Controller* ele);
		Controller* getCmd(sf::Keyboard::Key index);
		void executar(sf::Event* e);
		~CompositeController() { cmdMap.clear(); pref = nullptr; mref = nullptr; }
	};
}

