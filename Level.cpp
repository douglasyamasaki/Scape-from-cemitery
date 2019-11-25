#include "Level.h"
#include "Player.h"
#include <fstream>
#include <iostream>
using namespace std;

Level::Level()
{
	hudtexture = HUDModel::getInstance();
	collider.setEnemiesList(&enemies);
	collider.setProjectileList(&projectiles);
	collider.setStaticList(&platforms);
	collider.setObstacleList(&obstacles);
	lvlstateh.setEnemies(&enemies);
	lvlstateh.setProjectiles(&projectiles);
	lvlstateh.setStatics(&obstacles);
	hudp1.setSize(sf::Vector2f(349, 202));
	hudp1.setTexture(hudtexture->getP1());
	hudp1.setPosition(sf::Vector2f(0.0f, 0.0f));
	hudp2.setSize(sf::Vector2f(349, 202));
	hudp2.setTexture(hudtexture->getP2());
	hudp2.setPosition(sf::Vector2f(931.0f, 0.0f));
	potion.setSize(sf::Vector2f(22.4, 26.8));
	potion.setTexture(hudtexture->getPotion());
	potion.setPosition(188, 174.8);
}

sf::RectangleShape Level::getCenter()
{
	if (getP2ref() != nullptr) {
		///terminar
	}
	return sf::RectangleShape();
}

void Level::draw(sf::RenderWindow* window)
{
	for (platforms.it = platforms.getPrimeiro(); platforms.it.getIt() != nullptr; platforms.it++) {
		window->draw(*platforms.it.getIt()->getInfo());
	}
	for (enemies.it = enemies.getPrimeiro(); enemies.it.getIt() != nullptr; enemies.it++) {
		window->draw(*enemies.it.getIt()->getInfo());
	}
	for (obstacles.it = obstacles.getPrimeiro(); obstacles.it.getIt() != nullptr; obstacles.it++) {
		window->draw(*obstacles.it.getIt()->getInfo());
	}
	window->draw(*p1);
	if (p2 != nullptr)
		window->draw(*p2);
	for (projectiles.it = projectiles.getPrimeiro(); projectiles.it.getIt() != nullptr; projectiles.it++) {
		window->draw(*projectiles.it.getIt()->getInfo());
	}
	// drawning hud....
	//aqui eh somente pra p1...
	window->setView(window->getDefaultView());
	window->draw(hudp1);
	sf::Text text;
	text.setFont(*hudtexture->getFont());
	text.setCharacterSize(20);
	string line;
	line = p1->getName();
	cout << line << endl;
	text.setString(line);
	text.setPosition(120, 48);
	window->draw(text);
	char buffer[64];
	_itoa_s(p1->getPoints(), buffer,64, 10);
	line = buffer;
	text.setString(line);
	text.setPosition(192, 127);
	window->draw(text);
	for (int i = 0; i < p1->getLives(); i++) {
		potion.setPosition(188 + 34 * i, 174.8);
		window->draw(potion);
	}
	line.clear();
	// fim do p1

	// comeco do p2
	if (p2 != nullptr) {
		window->draw(hudp2);
		text.setFont(*hudtexture->getFont());
		text.setCharacterSize(20);
		line = p2->getName();
		text.setString(line);
		text.setPosition(973, 48);
		window->draw(text);
		char buffer[64];
		_itoa_s(p2->getPoints(), buffer, 64, 10);
		line = buffer;
		text.setString(line);
		text.setPosition(955, 127);
		window->draw(text);
		for (int i = 0; i < p2->getLives(); i++) {
			potion.setPosition(937 + 34 * i, 174.8);
			window->draw(potion);
		}
	}
}

void Level::setP1ref(Player* p1)
{
	this->p1 = p1; collider.setP1r(p1); lvlstateh.setP1(p1); p1->setList(&projectiles);
}

void Level::setP2ref(Player* p2)
{
	this->p2 = p2; collider.setP2r(p2); lvlstateh.setP2(p2); p2->setList(&projectiles);
}

void Level::setLost()
{
	bool checked = false;
	if (p1->getLives() <= 0) {
		checked = true;
	}
	if (p2 != nullptr) {
		if (p2->getLives() <= 0){
			if (checked == true)
				lost = true;
		}
		else {
			return;
		}
	}
	if (checked == true)
		lost = true;
}

void Level::savePoints()
{
	ofstream myfile;
	myfile.open("ranking.txt", std::ios::app);
	if (p1 != nullptr){
		myfile << p1->getName() << endl;
		myfile << p1->getPoints() << endl;
	}
	if (p2 != nullptr) {
		myfile << p2->getName() << endl;
		myfile << p2->getPoints() << endl;
	}
	if (p1 != nullptr && p2 != nullptr) {
		myfile << p1->getName() << " & " << p2->getName()<<endl;
		myfile << (p1->getPoints() + p2->getPoints()) << endl;
	}

}

void Level::load(){
	lvlstateh.load();
}
void Level::clear() {
	projectiles.clean();
	enemies.clean();
	obstacles.clean();
}
void Level::save() {
	lvlstateh.save();
}
