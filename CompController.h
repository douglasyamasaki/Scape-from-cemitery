#pragma once
#include "Player.h"
#include <map>
using namespace std;
namespace CompController {
	class CompositeController;
	class Controller {
	protected:
		Player* ref;
		bool active;
	public:
		virtual void setRef(Player* ref) { this->ref = ref; }
		Controller(Player* ref) { this->ref = ref; active = false; }
		Controller() { ref = nullptr; active = false; };
		virtual void executar(sf::Event* e) { };
		void on() { active = true; }
		void off() { active = false; }
		Player* getRef() const { return ref; }
		const bool getActive() const { return active; }
		virtual void add(int key, Controller ele) {};
		virtual Controller* getCmd(int index) { return nullptr; };
	};

	class CompositeController : public Controller {
	private:
		bool active;
		map<sf::Keyboard::Key, Controller*> cmdMap;
	public:
		void setRef(Player* ref) {
			this->ref = ref;
			map<sf::Keyboard::Key, Controller*>::iterator it;
			for (it = cmdMap.begin(); it != cmdMap.end(); ++it) {
				it->second->setRef(ref);
			}
		}
		CompositeController() : Controller() {}
		void add(sf::Keyboard::Key key, Controller* ele) {
			cmdMap.insert(pair<sf::Keyboard::Key, Controller*>(key, ele));
		}
		Controller* getCmd(sf::Keyboard::Key index) {
			out_of_range;
			Controller* aux;
			try {
				aux = cmdMap.at(index);
			}
			catch (out_of_range) {
				aux = nullptr;
			}
			return aux;
		}
		void executar(sf::Event* e) {
			Controller* aux;
			map<sf::Keyboard::Key, Controller*>::iterator it;
			if (e->type == sf::Event::KeyPressed) {
				aux = getCmd(e->key.code);
				if (aux != nullptr)
					aux->on();
			}
			if (e->type == sf::Event::KeyReleased) {
				aux = getCmd(e->key.code);
				if (aux != nullptr)
					aux->off();
			}
			for (it = cmdMap.begin(); it != cmdMap.end(); ++it) {
				if (it->second->getActive())
					it->second->executar(e);
			}
		}
	};

	class Up : public Controller {
	private:
	public:
		Up() : Controller() { }
		void executar(sf::Event* e) { if (ref != nullptr) ref->jump(); }
	};
	class Left : public Controller {
	private:
	public:
		Left() : Controller() { }
		void executar(sf::Event* e) { if (ref != nullptr) ref->moveLeft(); }
	};
	class Right : public Controller {
	private:
	public:
		Right() : Controller() { }
		void executar(sf::Event* e) { if (ref != nullptr) ref->moveRight(); }
	};

}