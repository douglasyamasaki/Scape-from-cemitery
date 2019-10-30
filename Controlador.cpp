#include "Controlador.h"

Controlador::Controlador()
{
	p1up = sf::Keyboard::Key::W;
	p1left = sf::Keyboard::Key::A;
	p1right = sf::Keyboard::Key::D;
	controllers[0].add(p1up, &upleaf);
	controllers[0].add(p1right, &rightleaf);
	controllers[0].add(p1left, &leftleaf);

}

void Controlador::update(sf::Event* ev)
{
	for (int i = 0; i < 2; i++) {
		controllers[i].executar(ev);
	}
}
