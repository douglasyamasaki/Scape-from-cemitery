#include "ButtonsModel.h"
using namespace Models;

ButtonsModel* ButtonsModel::instance = 0;

ButtonsModel* ButtonsModel::getInstance()
{
	if (!instance)
		instance = new ButtonsModel();
	return instance;
}

ButtonsModel::ButtonsModel() {
	P1 = new sf::Texture();
	P2 = new sf::Texture();
	BossStage = new sf::Texture();
	Stage1 = new sf::Texture();
	Highscore = new sf::Texture();
	Load = new sf::Texture();
	MainMenu = new sf::Texture();
	Quit = new sf::Texture();
	Resume = new sf::Texture();
	Save = new sf::Texture();
	P1->loadFromFile("./Sprites/Buttons/P1.png");
	P2->loadFromFile("./Sprites/Buttons/P2.png");
	BossStage->loadFromFile("./Sprites/Buttons/BossStage.png");
	Stage1->loadFromFile("./Sprites/Buttons/Stage1.png");
	Highscore->loadFromFile("./Sprites/Buttons/Highscore.png");
	Load->loadFromFile("./Sprites/Buttons/Load.png");
	MainMenu->loadFromFile("./Sprites/Buttons/MainMenu.png");
	Quit->loadFromFile("./Sprites/Buttons/Quit.png");
	Resume->loadFromFile("./Sprites/Buttons/Resume.png");
	Save->loadFromFile("./Sprites/Buttons/Save.png");
}