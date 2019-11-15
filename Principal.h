#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include <iostream>
#include "EventHandler.h"
#include "MenuHandler.h"
#include "Level.h"
using namespace std;
static const float VIEW_HEIGHT = 720.0f;
static const float VIEW_WIDTH = 1280.0f;

class Principal
{
private:
	EventHandler controle;
	sf::RenderWindow window;
	sf::Clock clock;
	float deltat;
	void ResizeView(const sf::RenderWindow& window, sf::View& view);
	sf::View view;
	MenuHandler mh;
	Level* levelref;
	Player* p1;
public:
	sf::RenderWindow* getWindow() { return &window; }
	Principal();
	void startDefaultLevel(int index);
	void resetView() { window.setView(window.getDefaultView()); }
	void executar();
};

