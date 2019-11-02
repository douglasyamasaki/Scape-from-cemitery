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
	sf::Keyboard::Key p1attack01;
	sf::Keyboard::Key p1attack02;
	sf::Keyboard::Key p1attack03;
	Up upleaf;
	Right rightleaf;
	Left leftleaf;
	Attack01 attack01;
	Attack02 attack02;
	Attack03 attack03;

public:
	Controlador();
	void setP1(Player* p1) { controllers[0].setRef(p1); }
	void setP2(Player* p2) { controllers[1].setRef(p2); }
	void update(sf::Event* ev);
	
};

