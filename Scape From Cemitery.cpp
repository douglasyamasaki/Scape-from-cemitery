#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include "Listas.h"
#include <iostream>
#include "Controlador.h"
using namespace std;
using namespace Lists;
static const float VIEW_HEIGHT = 720;
static const float VIEW_WIDTH= 1280;

void ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT*aspectRatio, VIEW_HEIGHT);
}

int main()
{
	Player P1(sf::Vector2f(250, 200), sf::Vector2f(150, -300), 100, sf::Vector2f(101, 131), sf::Vector2f(15, -20));
	Controlador controle;
	controle.setP1(&P1);
	sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "SFML works!");
	window.setKeyRepeatEnabled(true);
	sf::Clock clock;
	float deltat = 0;
	Platform plat1(sf::Vector2f(500, 200), sf::Vector2f(100, 0));
	Platform plat2(sf::Vector2f(500, 200), sf::Vector2f(600, 0));
	plat2.setFillColor(sf::Color::Green);
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
	StaticList StList;
	StList + &plat1;
	StList + &plat2;

	

	while (window.isOpen())
	{
		deltat = clock.restart().asSeconds();
		sf::Event event;
		if (deltat > 1.0f / 20.0f)
			deltat = 1.0f / 20.0f;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}
			controle.update(&event);
		}
		P1.update(deltat);
		sf::Vector2f direction;
		for (StList.it = StList.getPrimeiro(); StList.it != nullptr; StList.it++) {
			if (StList.it.getIt()->getInfo()->getCollisor()->CheckCollision(P1.getCollisor(),direction,1.0f)) {
				P1.OnCollision(direction);
			}
		}
		controle.update(&event);
		window.clear();
		window.setView(view);
		view.setCenter(P1.getHit().getPosition());
		window.draw(P1.getHit());
		window.draw(P1);
		window.draw(plat1);
		window.draw(plat2);
		window.display();
	}
	return 0;
}
