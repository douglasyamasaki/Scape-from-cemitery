#include "EventHandler.h"

EventHandler::EventHandler(MenuHandler* mhref)
{
		this->mhref = mhref;
		p1up = sf::Keyboard::Key::W;
		p1left = sf::Keyboard::Key::A;
		p1right = sf::Keyboard::Key::D;
		p1attack01 = sf::Keyboard::Key::X;
		p1attack03 = sf::Keyboard::Key::V;
		p1attack02 = sf::Keyboard::Key::C;

		p2up = sf::Keyboard::Key::I;
		p2left = sf::Keyboard::Key::J;
		p2right = sf::Keyboard::Key::L;
		p2attack01 = sf::Keyboard::Key::B;
		p2attack03 = sf::Keyboard::Key::N;
		p2attack02 = sf::Keyboard::Key::M;

		pause = sf::Keyboard::Key::P;
		enter = sf::Keyboard::Key::Enter;
		ecmd.setMenuHandler(mhref);
		mclick.setMenuHandler(mhref);
		pcommand.setMenuHandler(mhref);
		click = static_cast<sf::Keyboard::Key>(999);
		controllers[1].add(p1up, &upleaf);
		controllers[1].add(p1right, &rightleaf);
		controllers[1].add(p1left, &leftleaf);
		controllers[1].add(p1attack01, &attack01);
		controllers[1].add(p1attack02, &attack02);
		controllers[1].add(p1attack03, &attack03);
		controllers[0].add(click, &mclick);
		controllers[0].add(pause, &pcommand);
		controllers[0].add(enter, &ecmd);
		controllers[1].add(p2up, &upleaf);
		controllers[1].add(p2right, &rightleaf);
		controllers[1].add(p2left, &leftleaf);
		controllers[1].add(p2attack01, &attack01);
		controllers[1].add(p2attack02, &attack02);
		controllers[1].add(p2attack03, &attack03);

}

void EventHandler::update(sf::Event* ev)
{
	for (int i = 0; i < 2; i++) {
		controllers[i].executar(ev);
	}
}
