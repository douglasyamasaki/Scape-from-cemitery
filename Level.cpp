#include "Level.h"
#include "Player.h"

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
