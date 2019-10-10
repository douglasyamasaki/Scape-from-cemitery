#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include <iostream>
using namespace std;
static const float VIEW_HEIGHT = 720;
static const float VIEW_WIDTH= 1280;

void ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT*aspectRatio, VIEW_HEIGHT);
}
int main()
{
	Player P1(sf::Vector2f(250, 200), sf::Vector2f(150, -300), 100,sf::Vector2f(131,161));
	sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "SFML works!");
	sf::Clock clock;
	float deltat = 0;
	Platform plat1(sf::Vector2f(500, 200), sf::Vector2f(100, 0));
	Platform plat2(sf::Vector2f(500, 200), sf::Vector2f(600, 0));
	plat2.setFillColor(sf::Color::Green);
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
	while (window.isOpen())
	{
		deltat = clock.restart().asSeconds();
		sf::Event event;
		if (deltat > 1.0f / 20.0f)
			deltat = 1.0f / 20.0f;
		while (window.pollEvent(event))
		{
			switch (event.type){
			case sf::Event::Closed :
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}
		}
		sf::Vector2f direction;
		P1.update(deltat);
		if (plat1.getCollisor()->CheckCollision(P1.getCollisor(), direction, 1.0f)) {
			P1.OnCollision(direction);
		}
		window.clear();
		window.setView(view);
		view.setCenter(P1.getPosition());
		window.draw(P1);
		window.draw (P1.getHit());
		window.draw(plat1);
		window.draw(plat2);
		window.display();
	}
	return 0;
}
