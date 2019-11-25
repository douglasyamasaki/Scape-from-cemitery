#include "HUDModel.h"

HUDModel::HUDModel()
{
	P1 = new sf::Texture;
	P2 = new sf::Texture;
	Pot = new sf::Texture;
	Font = new sf::Font;
	P1->loadFromFile("./Sprites/HUD/P1HUD.png");
	P2->loadFromFile("./Sprites/HUD/P2HUD.png");
	Pot->loadFromFile("./Sprites/HUD/Potion.png");
	Font->loadFromFile("./Sprites/HUD/hud.otf");
}

HUDModel* HUDModel::getInstance()
{
	if (instance == nullptr)
		instance = new HUDModel();
	return instance;
}

HUDModel* HUDModel::instance = 0;