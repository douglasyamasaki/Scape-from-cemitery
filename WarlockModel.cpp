#include "WarlockModel.h"
using namespace Models;

WarlockModel* WarlockModel::instance = 0;

WarlockModel::WarlockModel()
{
	Rise = new sf::Texture;
	Idle = new sf::Texture;
	Die = new sf::Texture;
	Cast1 = new sf::Texture;
	Cast2 = new sf::Texture;
	Cast3 = new sf::Texture;
	Walk = new sf::Texture;
	Walk->loadFromFile("./Sprites/Warlock/Walk.png");
	Rise->loadFromFile("./Sprites/Warlock/Rise.png");
	Idle->loadFromFile("./Sprites/Warlock/Idle.png");
	Die->loadFromFile("./Sprites/Warlock/Die.png");
	Cast1->loadFromFile("./Sprites/Warlock/Cast01.png");
	Cast2->loadFromFile("./Sprites/Warlock/Cast02.png");
	Cast3->loadFromFile("./Sprites/Warlock/Cast03.png");
}

WarlockModel* WarlockModel::getInstance()
{
	if (!instance)
		instance = new WarlockModel();
	return instance;
}