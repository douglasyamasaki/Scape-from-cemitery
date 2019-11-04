#include "Principal.h"

void Principal::ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
void Principal::executar() {
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
			mh.update();
		}
		//controle.update(&event);
		window.display();
	}
}

Principal::Principal() : P1 (sf::Vector2f(250, 200), sf::Vector2f(150, -300), sf::Vector2f(100, 0), sf::Vector2f(101, 131), sf::Vector2f(15, -20), &arrowlist),
view(sf::Vector2f(0, 0), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT)),
window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Scape from Cemitery"),
plat1(sf::Vector2f(500, 200), sf::Vector2f(100, 0)),
plat2(sf::Vector2f(500, 200), sf::Vector2f(600, 0)),
mh(this),
controle(&mh)
{
	controle.setP1(&P1);
	StList + &plat1;
	StList + &plat2;
	executar();
}