#pragma once
#include "Player.h"
#include <map>
using namespace std;
namespace CompController {
	class CompositeController;
	class Controller {
	protected:
		Player* pref;
		bool active;
	public:
		virtual void setRef(Player* ref) { this->pref = ref; }
		Controller(Player* ref) { this->pref = ref; active = false; }
		Controller() { pref = nullptr; active = false; };
		virtual void executar(sf::Event* e) { };
		void on() { active = true; }
		void off() { active = false; }
		Player* getRef() const { return pref; }
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
			this->pref = ref;
			map<sf::Keyboard::Key, Controller*>::iterator it;
			for (it = cmdMap.begin(); it != cmdMap.end(); ++it) {
				it->second->setRef(ref);
			}
		}
		CompositeController() : Controller() { active = false; }
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
		void executar(sf::Event* e) { if (pref != nullptr) pref->jump(); }
	};
	class Left : public Controller {
	private:
	public:
		Left() : Controller() { }
		void executar(sf::Event* e) { if (pref != nullptr) pref->moveLeft(); }
	};
	class Right : public Controller {
	private:
	public:
		Right() : Controller() { }
		void executar(sf::Event* e) { if (pref != nullptr) pref->moveRight(); }
	};

	class Attack01 : public Controller {
	private:
	public:
		Attack01() : Controller() {}
		void executar(sf::Event* e) {
			if (pref != nullptr && !pref->getLock()) {
				pref->setLock();
				pref->setAttType(1);
				pref->reset();
			} 
		}
	};

	class Attack02 : public Controller {
	private:
	public:
		Attack02() : Controller() {}
		void executar(sf::Event* e) {
			if (pref != nullptr && !pref->getLock()) {
				pref->setLock();
				pref->setAttType(2);
				pref->reset();
			}
		}
	};
	class Attack03 : public Controller {
	private:
	public:
		Attack03() : Controller() {}
		void executar(sf::Event* e) {
			if (pref != nullptr && !pref->getLock()) {
				pref->setLock();
				pref->setAttType(3);
				pref->reset();
			}
		}
	};

	class MenuClick : public Controller {
	private:
	public:
		MenuClick() : Controller() {

		}
	};
}