#include "MenuModel.h"
using namespace Models;
MenuModel* MenuModel::instance = 0;

MenuModel* MenuModel::getInstance()
{
	if (!instance)
		instance = new MenuModel();
	return instance;
}

MenuModel::MenuModel() {
	Pause = new sf::Texture();
	Win = new sf::Texture();
	Lose = new sf::Texture();
	Selection = new sf::Texture();
	Ranking = new sf::Texture();
	Main = new sf::Texture();
	Naming = new sf::Texture();
	Naming->loadFromFile("./Sprites/Menu/Naming.png");
	Pause->loadFromFile("./Sprites/Menu/Pause.png");
	Win->loadFromFile("./Sprites/Menu/Win.png");
	Lose->loadFromFile("./Sprites/Menu/Lose.png");
	Selection->loadFromFile("./Sprites/Menu/Selection.png");
	Ranking->loadFromFile("./Sprites/Menu/Ranking.png");
	Main->loadFromFile("./Sprites/Menu/Main.png");
}
