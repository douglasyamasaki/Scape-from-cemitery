#include "Controlador.h"
#define Click 999;

Controlador::Controlador(MenuHandler* mhref)
{
	p1up = sf::Keyboard::Key::W;
	p1left = sf::Keyboard::Key::A;
	p1right = sf::Keyboard::Key::D;
	p1attack01 = sf::Keyboard::Key::C;
	p1attack03 = sf::Keyboard::Key::B;
	p1attack02 = sf::Keyboard::Key::V;
	pause = sf::Keyboard::Key::P;
	mclick.setMenuHandler(mhref);
	pcommand.setMenuHandler(mhref);
	click = static_cast<sf::Keyboard::Key>(999);
	controllers[0].add(p1up, &upleaf);
	controllers[0].add(p1right, &rightleaf);
	controllers[0].add(p1left, &leftleaf);
	controllers[0].add(p1attack01, &attack01);
	controllers[0].add(p1attack02, &attack02);
	controllers[0].add(p1attack03, &attack03);
	controllers[0].add(click, &mclick);
	controllers[0].add(pause, &pcommand);

}

void Controlador::update(sf::Event* ev)
{
	for (int i = 0; i < 2; i++) {
		controllers[i].run(ev);
	}
}
