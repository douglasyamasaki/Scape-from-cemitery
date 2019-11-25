#include "Level.h"
#include "Player.h"
#include <fstream>

Level::Level()
{
	collider.setEnemiesList(&enemies);
	collider.setProjectileList(&projectiles);
	collider.setStaticList(&platforms);
	collider.setObstacleList(&obstacles);
	lvlstateh.setEnemies(&enemies);
	lvlstateh.setProjectiles(&projectiles);
	lvlstateh.setStatics(&obstacles);
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
		myfile << p1->getName() << endl;
		myfile << p1->getPoints() << endl;
	}
	if (p1 != nullptr && p2 != nullptr) {
		myfile << p1->getName() << " & " << p2->getName()<<endl;
		myfile << (p1->getPoints() + p2->getPoints());
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
