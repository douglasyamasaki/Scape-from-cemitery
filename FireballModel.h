#pragma once
#include <SFML/Graphics.hpp>
class FireballModel
{
private:
	sf::Texture* Fireball;
	FireballModel();
	static FireballModel* instance;
public:
	sf::Texture* getFireball() { return Fireball; }
	static FireballModel* getInstance();
};

