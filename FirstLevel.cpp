#include "FirstLevel.h"
#include "Platform.h"
#include "Player.h"
FirstLevel::FirstLevel() : Level()
{
}
void FirstLevel::load_static()
{
	Platform* chao = new Platform(sf::Vector2f(10000, 1000), sf::Vector2f(0, 0));
	platforms + chao;
}

void FirstLevel::load_default() {
	load_static();
	p1 = new Player(sf::Vector2f(250,200), sf::Vector2f(0,-300), sf::Vector2f(100,0),sf::Vector2f(101,131), sf::Vector2f(15,-20),&projectiles);
	
}

void FirstLevel::update(float deltat)
{
	p1->update(deltat);
	if (p2 != nullptr)
		p2->update(deltat);
	// update section
	for (enemies.it = enemies.getPrimeiro(); enemies.it.getIt() != nullptr; enemies.it++) {
		enemies.it.getIt()->getInfo()->update(deltat);
	}
	for (projectiles.it = projectiles.getPrimeiro(); projectiles.it.getIt(); projectiles.it++) {
		projectiles.it.getIt()->getInfo()->update(deltat);
	}
	// collision section
	for (platforms.it = platforms.getPrimeiro(); platforms.it.getIt() != nullptr; platforms.it++) {
		sf::Vector2f direction;
		// Colisao de inimigo com player e inimigo com as plataformas
		direction = sf::Vector2f(0, 0);
		for (enemies.it = enemies.getPrimeiro(); enemies.it.getIt() != nullptr; enemies.it++) {
			//Ghost* ghstptr = dynamic_cast<Ghost*>(enemies.it.getIt()->getInfo());
			///if (ghstpr == nullptr) {
			if(platforms.it.getIt()->getInfo()->getCollisor()->CheckCollision(enemies.it.getIt()->getInfo()->getCollisor(), direction, 1.0f))
				enemies.it.getIt()->getInfo()->OnCollision(direction);
			//}
			if(enemies.it.getIt()->getInfo()->getCollisor()->CheckCollision(p1->getCollisor(), direction, 1.0f))
				p1->OnCollision(direction); // on hit
			if (p2 != nullptr) {
				if(enemies.it.getIt()->getInfo()->CheckCollision(p2->getCollisor(), direction, 1.0f))
					p2->OnCollision(direction); // on hit
			}
		}
		direction = sf::Vector2f(0, 0);
		//colisao de plataforma com flechas
		for (projectiles.it = projectiles.getPrimeiro(); projectiles.it.getIt() != nullptr; projectiles.it++) {
			if (platforms.it.getIt()->getInfo()->CheckCollision(projectiles.it.getIt()->getInfo()->getCollisor(), direction, 1.0f))
				projectiles.remove();
		}
		direction = sf::Vector2f(0, 0);
		// Colisao de plataforma com players
		platforms.it.getIt()->getInfo()->getCollisor()->CheckCollision(p1->getCollisor(), direction, 1.0f);
		p1->OnCollision(direction);
		if (p2 != nullptr) {
			platforms.it.getIt()->getInfo()->getCollisor()->CheckCollision(p2->getCollisor(), direction, 1.0f);
			p2->OnCollision(direction);
		}
	}
	//colisao de projeteis : (fase 1 nao tem boss , ou seja , nao tem ref a player
	for (projectiles.it = projectiles.getPrimeiro(); projectiles.it.getIt() != nullptr; projectiles.it++) {
		sf::Vector2f direction;
		direction = sf::Vector2f(0, 0);
		for (enemies.it = enemies.getPrimeiro(); enemies.it.getIt() != nullptr; enemies.it++) {
			if (projectiles.it.getIt()->getInfo()->getCollisor()->CheckCollision(enemies.it.getIt()->getInfo()->getCollisor(), direction, 1.0f)){
				//enemie on hit
				projectiles.remove();
			}
		}

	}
}
