#pragma once
#include "Inimigo.h"
#include "Models.h"
#include "Listas.h"
using namespace Lists;
using namespace SpriteModels;

class Player;
class Warlock : public Inimigo
{
private:
	Player* p1;
	Player* p2;
	ProjectileList* projeteis;
	BossModel* textures;
	void UpdateTexture();
	int attacktype;

	void move();
	void seek();
	void attack();
	void randomizeattack();
public:
	void onHit(sf::Vector2f direction);
	Warlock (sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento, const float reward);
	void update(float deltat);
	void setP1(Player* p1) { this->p1 = p1; }
	void setP2(Player* p2) { this->p2 = p2; }
	
};

