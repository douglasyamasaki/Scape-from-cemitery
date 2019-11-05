#include "Principal.h"
#include "FirstLevel.h"
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
		window.clear();
		if (mh.getActive())
			mh.update();
		else {
			controle.update(&event);
			if (levelref != nullptr){
				levelref->update(deltat);
				window.setView(view);
				view.setCenter(p1->getCollisor()->getHBPos());
				levelref->draw(&window);
				window.draw(*p1);
			}
		}
		window.display();
	}
}

Principal::Principal() : view(sf::Vector2f(0, 0), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT)),
window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Scape from Cemitery"),
mh(this),
controle(&mh)
{
	executar();
}

void Principal::startDefaultLevel(int index)
{
	if (index == 1) {
		levelref = new FirstLevel();
	}
	levelref->load_default();
	controle.setP1(levelref->getP1ref());
	controle.setP2(levelref->getP2ref());
	p1 = levelref->getP1ref();
}
