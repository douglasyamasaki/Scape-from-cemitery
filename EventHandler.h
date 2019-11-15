#pragma once
#include "Attack01Command.h"
#include "Attack02Command.h"
#include "Attack03Command.h"
#include "CompositeController.h"
#include "Controller.h"
#include "LeftCommand.h"
#include "MenuClickCommand.h"
#include "PauseCommand.h"
#include "UpCommand.h"
#include "RightCommand.h"
using namespace CompController;
class EventHandler
{
private:
	CompositeController controllers[2];
	sf::Keyboard::Key p1up;
	sf::Keyboard::Key p1left;
	sf::Keyboard::Key p1right;
	sf::Keyboard::Key p1attack01;
	sf::Keyboard::Key p1attack02;
	sf::Keyboard::Key p1attack03;
	sf::Keyboard::Key click;
	sf::Keyboard::Key pause;
	UpCommand upleaf;
	RightCommand rightleaf;
	LeftCommand leftleaf;
	Attack01Command attack01;
	Attack02Command attack02;
	Attack03Command attack03;
	MenuClickCommand mclick;
	MenuHandler* mhref;
	PauseCommand pcommand;
public:
	EventHandler(MenuHandler* mhref);
	void setP1(Player* p1) { controllers[0].setRef(p1); }
	void setP2(Player* p2) { controllers[1].setRef(p2); }
	void update(sf::Event* ev);
};

