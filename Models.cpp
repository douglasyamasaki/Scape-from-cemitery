#include "Models.h"
using namespace SpriteModels;

ArcherModel* ArcherModel::instance = 0;
ArrowModel* ArrowModel::instance = 0;
GhostModel* GhostModel::instance = 0;
MenuModel* MenuModel::instance = 0;
ButtonModel* ButtonModel::instance = 0;

ArcherModel* ArcherModel::getInstance(){
	if (!instance)
		instance = new ArcherModel();
	return instance;
}

ArcherModel::ArcherModel() {
	Walk = new sf::Texture();
	Idle = new sf::Texture();
	JumpUp = new sf::Texture();
	JumpDown = new sf::Texture();
	Attack01 = new sf::Texture();
	Attack02 = new sf::Texture();
	Attack03 = new sf::Texture();
	Walk->loadFromFile("./Sprites/Skeleton/Walk.png");
	Idle->loadFromFile("./Sprites/Skeleton/Idle.png");
	JumpUp->loadFromFile("./Sprites/Skeleton/Jump Up.png");
	JumpDown->loadFromFile("./Sprites/Skeleton/Jump Down.png");
	Attack01->loadFromFile("./Sprites/Skeleton/Attack01.png");
	Attack02->loadFromFile("./Sprites/Skeleton/Attack02.png");
	Attack03->loadFromFile("./Sprites/Skeleton/Attack03.png");
}

ArrowModel* ArrowModel::getInstance() {
	if (!instance)
		instance = new ArrowModel();
	return instance;
}

ArrowModel::ArrowModel() {
	Arrow = new sf::Texture();
	Arrow->loadFromFile("./Sprites/Skeleton/Arrow.png");
}

GhostModel::GhostModel() {
	Ghost = new sf::Texture();
	Ghost->loadFromFile("./Sprites/Enemies/Ghost/Ghost.png");
}

MenuModel::MenuModel() {
	Pause = new sf::Texture();
	Win = new sf::Texture();
	Lose = new sf::Texture();
	Selection = new sf::Texture();
	Ranking = new sf::Texture();
	Main = new sf::Texture();
	Pause->loadFromFile("./Sprites/Menu/Pause.png");
	Win->loadFromFile("./Sprites/Menu/Pause.png");
	Lose->loadFromFile("./Sprites/Menu/Pause.png");
	Selection->loadFromFile("./Sprites/Menu/Pause.png");
	Ranking->loadFromFile("./Sprites/Menu/Pause.png");
	Main->loadFromFile("./Sprites/Menu/Pause.png");
}

ButtonModel::ButtonModel() {
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

MenuModel* MenuModel::getInstance()
{
	if (!instance)
		instance = new MenuModel();
	return instance;
}

ButtonModel* ButtonModel::getInstance()
{
	if (!instance)
		instance = new ButtonModel();
	return instance;
}