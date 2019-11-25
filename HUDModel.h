#pragma once
#include <SFML/Graphics.hpp>
class HUDModel
{
private:
	sf::Texture* P1;
	sf::Texture* P2;
	sf::Texture* Pot;
	sf::Font* Font;
	static HUDModel* instance;
	HUDModel();
public:
	sf::Texture* getP1() { return P1; }
	sf::Texture* getP2() { return P2; }
	sf::Texture* getPotion() { return Pot; }
	sf::Font* getFont() { return Font; }
	static HUDModel* getInstance();
};

