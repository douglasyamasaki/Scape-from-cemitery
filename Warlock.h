#pragma once
#include "Enemie.h"
#include "WarlockModel.h"
#include "EnemiesList.h"
#include "ProjectileList.h"
using namespace Models;

class Player;
class Warlock : public Enemie
{
private:
	Player* p1;
	Player* p2;
	ProjectileList* projeteis;
	WarlockModel* textures;
	void UpdateTexture();
	int attacktype;

	void move();
	void seek();
	void attack();
	void randomizeattack();
public:
	void onHit(sf::Vector2f direction);
	Warlock (sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento, const float reward, ProjectileList* ref);
	void update(float deltat);
	void setP1(Player* p1) { this->p1 = p1; }
	void setP2(Player* p2) { this->p2 = p2; }
	
};

