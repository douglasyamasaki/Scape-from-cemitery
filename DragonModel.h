#pragma once
#include <SFML/Graphics.hpp>
class DragonModel
{
private:
	sf::Texture* Dragon;
	DragonModel();
	static DragonModel* instance;
public:
	sf::Texture* getDragon() { return Dragon; }
	static DragonModel* getInstance();
};

