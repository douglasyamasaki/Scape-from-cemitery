#include "Principal.h"
#include "FirstLevel.h"


void Principal::ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
void Principal::manageLevel()
{
	if (levelref->getFinished()) {
		if (leveltype == 1)
			printf("temp");//logica para o level2
		else {
			mh.switchTowmenu();
			mh.turnOn();
		}
	}
	if (levelref->getLost()) {
		levelref->savePoints();
		mh.switchTolmenu();
		mh.turnOn();
	}
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
			case sf::Event::TextEntered:
				if (mh.getActive())
					mh.update(&event);
			}
			controle.update(&event);
		}
		window.clear();
		if (mh.getActive())
			mh.update(nullptr);
		else {
			controle.update(&event);
			if (levelref != nullptr){
				levelref->update(deltat);
				window.setView(view);
				view.setCenter(p1->getBody()->getHBPos());
				levelref->draw(&window);
				manageLevel();
			}
		}
		window.display();
	}
}

void Principal::load()
{
	printf("carregou");
}

void Principal::save()
{
	levelref->save();
}

void Principal::clearcurrentlevel()
{
	printf("clearou");
}

void Principal::setName(const int index, const string name)
{
	if (index == 1 && p1 != nullptr)
		p1->setName(name);
	else if (index == 2 && p2 != nullptr)
		p2->setName(name);
}

Principal::Principal() : view(sf::Vector2f(0, 0), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT)),
window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Scape from Cemitery"),
mh(this),
controle(&mh)
{
	p1 = new Player(sf::Vector2f(250, 200), sf::Vector2f(0, 0), sf::Vector2f(100, 0), sf::Vector2f(101, 131), sf::Vector2f(15, -20), nullptr);
	p2 = new Player(sf::Vector2f(250, 200), sf::Vector2f(0, 0), sf::Vector2f(100, 0), sf::Vector2f(101, 131), sf::Vector2f(15, -20), nullptr);
	controle.setP1(p1);
	controle.setP2(p2);
	hasp2 = false;
	levelref = nullptr;
	leveltype = -1;
	executar();
}

Principal::~Principal()
{
	delete p1;
	delete p2;
}

void Principal::startDefaultLevel(int index)
{
	if (index == 1) {
		levelref = new FirstLevel();
	}
	levelref->setP1ref(p1);
	if (hasp2)
		levelref->setP2ref(p2);
	levelref->load_default();
	leveltype = index;
}
