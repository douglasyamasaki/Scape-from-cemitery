#include "MenuBase.h"
#include "MenuButtonBase.h"
#include "MenuHandler.h"
#include "Principal.h"
void MenuBase::drawMenu()
{
	vector<MenuButtonBase*>::iterator it;
	MHref->getPrincipal()->getWindow()->draw(*this);
	for (it = buttons.begin(); it != buttons.end(); it++) {
		MHref->getPrincipal()->getWindow()->draw(**it);
	}
}

void MenuBase::input(sf::Vector2f cinput) {
	vector<MenuButtonBase*>::iterator it;
	MenuButtonBase* aux;
	for (it = buttons.begin(); it != buttons.end(); it++) {
		aux = *it;
		if (cinput.x > aux->getPosition().x&& cinput.x < aux->getPosition().x + aux->getSize().x)
			if (cinput.y > aux->getPosition().y&& cinput.y < aux->getPosition().y + aux->getSize().y)
				(*it)->run();
	}
}