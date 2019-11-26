#pragma once
#include "Enemie.h"
using namespace AbstractEntity;
#include "DragonModel.h"
#include "ProjectileList.h"
class Player;
class Dragon : public Enemie
{
private:
	ProjectileList* listref;
	Player* p1t;
	Player* p2t;
	DragonModel* texture;
	float accumulator;
public:
	Dragon(sf::Vector2f pos);
	~Dragon(){delete(instance);}
	void onHit(sf::Vector2f direction);
	void seek();
	void update(float deltat);
	void setP1t(Player* target) { p1t = target; }
	void setP2t(Player* target) { p2t = target; }
	void setAccumulator(const float accumulator) { this->accumulator = accumulator; }
	void setList(ProjectileList* list) { listref = list; }
	const float getAccumulator() const { return accumulator; }
};

