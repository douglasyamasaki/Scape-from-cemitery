#pragma once
#include <SFML/Graphics.hpp>
class Body{
protected:
	sf::RectangleShape hitbox;
	sf::Vector2f deslocamento;
public:
	Body(sf::Vector2f size);
	Body (sf::Vector2f size, sf::Vector2f deslocamento,sf::Vector2f cmpos);
	sf::Vector2f getHBPos() { return hitbox.getPosition(); }
	sf::Vector2f getHalfsize() { return hitbox.getSize() / 2.0f; }
	void moveHB(float dx, float dy) { hitbox.move(dx, dy); }
	Body* getBody() { return this; }
};

