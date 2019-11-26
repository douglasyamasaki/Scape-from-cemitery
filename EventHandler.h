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
#include "EnterCommand.h"
using namespace CompController;
class EventHandler
{
private:
	CompositeController* controllers;
	sf::Keyboard::Key p1up;
	sf::Keyboard::Key p1left;
	sf::Keyboard::Key p1right;
	sf::Keyboard::Key p1attack01;
	sf::Keyboard::Key p1attack02;
	sf::Keyboard::Key p1attack03;
	sf::Keyboard::Key p2up;
	sf::Keyboard::Key p2left;
	sf::Keyboard::Key p2right;
	sf::Keyboard::Key p2attack01;
	sf::Keyboard::Key p2attack02;
	sf::Keyboard::Key p2attack03;

	sf::Keyboard::Key click;
	sf::Keyboard::Key pause;
	sf::Keyboard::Key enter;
	MenuClickCommand mclick;
	EnterCommand ecmd;
	MenuHandler* mhref;
	PauseCommand pcommand;
public:
	EventHandler(MenuHandler* mhref);
	void setP1(Player* p1);
	void setP2(Player* p2);
	void restartcontrollers();
	void update(sf::Event* ev);
};

