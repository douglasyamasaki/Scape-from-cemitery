#pragma once
#include "CompController.h"
using namespace CompController;
class Controlador
{
private:
	CompositeController controllers[2];
	sf::Keyboard::Key p1up;
	sf::Keyboard::Key p1left;
	sf::Keyboard::Key p1right;
	Up upleaf;
	Right rightleaf;
	Left leftleaf;

public:
	Controlador();
	void setP1(Player* p1) { controllers[0].setRef(p1); }
	void setP2(Player* p2) { controllers[1].setRef(p2); }
	void update(sf::Event* ev);
	
};

