#include "Principal.h"
#include "FirstLevel.h"
#include <fstream>


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
	int aux,aux2;
	float faux1, faux2;
	string saux;
	ifstream infile("./Save/Base.txt", ios::in);
	infile >> aux;
	if (aux == 1)
		levelref = &first;
	/*else
		levelref = &second;
	*/
	infile >> aux;
	levelref->getStateHandler()->setwProj(aux);
	infile >> aux;
	levelref->getStateHandler()->setwEnemies(aux);
	infile >> aux;
	levelref->getStateHandler()->setwObj(aux);
	infile >> aux;
	if (aux == 2)
		hasp2 = true;
	infile.close();
	
	// logica do p1
	infile.open("./Save/P1.txt", ios::in);
	infile >> saux;
	p1->setName(saux);
	infile >> aux;
	p1->increasePoints(aux);
	infile >> aux;
	p1->setLives(aux);
	infile >> aux;
	p1->setAttType(aux);
	infile >> faux1;
	infile >> faux2;
	p1->setPos(sf::Vector2f(faux1, faux2));
	infile >> faux1;
	infile >> faux2;
	p1->setVelocity(sf::Vector2f(faux1, faux2));
	infile >> aux;
	if (aux == 1)
		p1->setLock();
	infile >> aux;
	p1->setFrame(aux);
	infile >> aux;
	infile >> aux2;
	p1->setimgI(sf::Vector2u(aux, aux2));
	infile >> aux;
	if (aux == 1) {
		p1->setInvulneravel();
		p1->setFillColor(sf::Color::Red);
	}
	infile >> aux;
	if (aux == 1) {
		p1->setFaceright(true);
	}
	else
		p1->setFaceright(false);
	infile.close();
	// logica do p2
	if (hasp2) {
		infile.open("./Save/P2.txt", ios::in);
		infile >> saux;
		p2->setName(saux);
		infile >> aux;
		p2->increasePoints(aux);
		infile >> aux;
		p2->setLives(aux);
		infile >> aux;
		p2->setAttType(aux);
		infile >> faux1;
		infile >> faux2;
		p2->setPos(sf::Vector2f(faux1, faux2));
		infile >> faux1;
		infile >> faux2;
		p2->setVelocity(sf::Vector2f(faux1, faux2));
		infile >> aux;
		if (aux == 1)
			p2->setLock();
		infile >> aux;
		p2->setFrame(aux);
		infile >> aux;
		infile >> aux2;
		p2->setimgI(sf::Vector2u(aux, aux2));
		infile >> aux;
		if (aux == 1) {
			p2->setInvulneravel();
			p2->setFillColor(sf::Color::Red);
		}
		infile >> aux;
		if (aux == 1) {
			p2->setFaceright(true);
		}
		else
			p2->setFaceright(false);
		infile.close();
		levelref->setP2ref(p2);
	}
	//
	levelref->setP1ref(p1);
	levelref->load();
	levelref->load_static();
	mh.switchTopmenu();


}

void Principal::save()
{
	levelref->save();
}

void Principal::clearcurrentlevel()
{
	delete p1;
	delete p2;
	if (levelref != nullptr)
		levelref->clear();
	p1 = new Player(sf::Vector2f(0.0f, 0.0f));
	p2 = new Player(sf::Vector2f(0.0f, 0.0f));
	controle.setP1(p1);
	controle.setP2(p2);
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
	p1 = new Player(sf::Vector2f(0, 0));
	p2 = new Player(sf::Vector2f(0, 0));
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
