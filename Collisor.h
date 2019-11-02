#pragma once
#include <SFML/Graphics.hpp>
class Collisor{
protected:
	sf::RectangleShape hitbox;
	sf::Vector2f deslocamento;
public:
	Collisor(sf::Vector2f size);
	Collisor (sf::Vector2f size, sf::Vector2f deslocamento,sf::Vector2f cmpos);
	bool CheckCollision(Collisor* other, sf::Vector2f& direction,float push);
	sf::Vector2f getHBPos() { return hitbox.getPosition(); }
	sf::Vector2f getHalfsize() { return hitbox.getSize() / 2.0f; }
	void moveHB(float dx, float dy) { hitbox.move(dx, dy); }
	Collisor* getCollisor() { return this; }
};

