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
	int attacktype;

	void move();
	void seek();
	void attack();
	void randomizeattack();
public:
	void loadTexture();
	void UpdateTexture();
	int getAttType() const { return attacktype; }
	void onHit(sf::Vector2f direction);
	Warlock ( sf::Vector2f pos,ProjectileList* ref);
	~Warlock(){ delete(textures);}
	void update(float deltat);
	void setP1(Player* p1) { this->p1 = p1; }
	void setP2(Player* p2) { this->p2 = p2; }
	void setAttType(const int type) { this->attacktype = type; }
	
};

