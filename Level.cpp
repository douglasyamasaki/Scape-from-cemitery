#include "Level.h"
#include "Player.h"
#include <fstream>

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
	for (projectiles.it = projectiles.getPrimeiro(); projectiles.it.getIt() != nullptr; projectiles.it++) {
		window->draw(*projectiles.it.getIt()->getInfo());
	}
	window->draw(*p1);
}

void Level::setLost()
{
	bool checked;
	if (p1->getLives() == 0) {
		checked = true;
	}
	if (p2 != nullptr) {
		if (p2->getLives() == 0){
			if (checked == true)
				lost = true;
		}
		else {
			return;
		}
	}
	if (checked = true)
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
		myfile << p1->getName() << endl;
		myfile << p1->getPoints() << endl;
	}
	if (p1 != nullptr && p2 != nullptr) {
		myfile << p1->getName() << " & " << p2->getName()<<endl;
		myfile << (p1->getPoints() + p2->getPoints());
	}

}
