#pragma once
#include <SFML/Graphics.hpp>

namespace Models{
class ButtonsModel
{
private:
	static ButtonsModel* instance;
	sf::Texture* P1;
	sf::Texture* P2;
	sf::Texture* BossStage;
	sf::Texture* Stage1;
	sf::Texture* Highscore;
	sf::Texture* Load;
	sf::Texture* MainMenu;
	sf::Texture* Quit;
	sf::Texture* Resume;
	sf::Texture* Save;
	ButtonsModel();
public:
	~ButtonsModel(){delete(instance);}
	static ButtonsModel* getInstance();
	sf::Texture* getP1() { return P1; }
	sf::Texture* getP2() { return P2; }
	sf::Texture* getBossStage() { return BossStage; }
	sf::Texture* getStage1() { return Stage1; }
	sf::Texture* getHighscore() { return Highscore; }
	sf::Texture* getLoad() { return Load; }
	sf::Texture* getMainMenu() { return MainMenu; }
	sf::Texture* getQuit() { return Quit; }
	sf::Texture* getResume() { return Resume; }
	sf::Texture* getSave() { return Save; }
};
}
