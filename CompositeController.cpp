#include "CompositeController.h"
using namespace CompController;

void CompController::CompositeController::setRef(Player* ref)
{
	this->pref = ref;
	map<sf::Keyboard::Key, Controller*>::iterator it;
	for (it = cmdMap.begin(); it != cmdMap.end(); ++it) {
		it->second->setRef(ref);
	}
}

void CompController::CompositeController::add(sf::Keyboard::Key key, Controller* ele)
{
	cmdMap.insert(pair<sf::Keyboard::Key, Controller*>(key, ele));
}

void CompController::CompositeController::executar(sf::Event* e)
{
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
	if (e->type == sf::Event::MouseButtonReleased) {
		int j = 999;
		aux = getCmd(static_cast<sf::Keyboard::Key>(j));
		if (aux != nullptr)
			aux->on();
	}
	for (it = cmdMap.begin(); it != cmdMap.end(); ++it) {
		if (it->second->getActive())
			it->second->executar(e);

	}
}

Controller* CompositeController::getCmd(sf::Keyboard::Key index) {
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
