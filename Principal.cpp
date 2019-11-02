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
		}
		P1.update(deltat);
		sf::Vector2f direction;
		for (StList.it = StList.getPrimeiro(); StList.it != nullptr; StList.it++) {
			if (StList.it.getIt()->getInfo()->getCollisor()->CheckCollision(P1.getCollisor(), direction, 1.0f)) {
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
		for (arrowlist.it = arrowlist.getPrimeiro(); arrowlist.it != nullptr; arrowlist.it++) {
			arrowlist.it.getIt()->getInfo()->update(deltat);
			window.draw(*arrowlist.it.getIt()->getInfo());
		}
		window.display();
	}
}

Principal::Principal() : P1 (sf::Vector2f(250, 200), sf::Vector2f(150, -300), sf::Vector2f(100, 0), sf::Vector2f(101, 131), sf::Vector2f(15, -20), &arrowlist),
view(sf::Vector2f(0, 0), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT)),
window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Scape from Cemitery"),
plat1(sf::Vector2f(500, 200), sf::Vector2f(100, 0)),
plat2(sf::Vector2f(500, 200), sf::Vector2f(600, 0))
{
	controle.setP1(&P1);
	StList + &plat1;
	StList + &plat2;
	executar();
}