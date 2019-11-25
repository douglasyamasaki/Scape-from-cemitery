#pragma once
#include <SFML/Graphics.hpp>
namespace Models{
class MenuModel
{
private:
	static MenuModel* instance;
	sf::Texture* Pause;
	sf::Texture* Win;
	sf::Texture* Lose;
	sf::Texture* Selection;
	sf::Texture* Ranking;
	sf::Texture* Main;
	sf::Texture* Naming;
	MenuModel();
public:
	static MenuModel* getInstance();
	sf::Texture* getNaming() { return Naming; }
	sf::Texture* getPause() { return Pause; }
	sf::Texture* getWin() { return Win; }
	sf::Texture* getLose() { return Lose; }
	sf::Texture* getSelection() { return Selection; }
	sf::Texture* getRanking() { return Ranking; }
	sf::Texture* getMain() { return Main; }
};
}

