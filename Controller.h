#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "MenuHandler.h"
namespace CompController {
	class Controller {
	protected:
		Player* pref;
		MenuHandler* mref;
		bool active = false;
	public:
		virtual void setRef(Player* ref) { this->pref = ref; }
		Controller(Player* ref) { this->pref = ref; active = false; mref = nullptr; }
		Controller() { pref = nullptr; active = false; mref = nullptr; };
		virtual void executar(sf::Event* e) { };
		void on() { active = true; }
		void off() { active = false; }
		Player* getRef() const { return pref; }
		const bool getActive() const { return active; }
		virtual void add(int key, Controller ele) {};
		virtual Controller* getCmd(int index) { return nullptr; };
	};
}