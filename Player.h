#pragma once
#include "ArcherModel.h"
#include "Animation.h"
#include "DynamicEntity.h"
#include "ProjectileList.h"
#include <string>
using namespace std;
using namespace Models;
using namespace AbstractEntity;

class Player : public DynamicEntity, public Animation {
private:
	ProjectileList* arrowlistref;
	ArcherModel* textures;
	sf::Vector2f velocity;
	string name;
	bool invulneravel;
	bool canJump;
	float jumpHeight;
	int lives;
	int pontos;
	int attacktype;
public:
	void attacktypex(const int index);
	void setList(ProjectileList* arrowlistref) { this->arrowlistref = arrowlistref; }
	void setName(string name) { this->name = name; }
	void setAttType(int valor) { attacktype = valor; }
	void attack();
	void updateTexture();
	void OnCollision(sf::Vector2f direction);
	Player(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento, ProjectileList* ref);
	void update(float deltat);
	sf::RectangleShape getHit() { return hitbox; }
	void jump();
	void moveRight();
	void moveLeft();
	const string getName() const  { return name; }
	void setPos(sf::Vector2f pos);
	void onHit(sf::Vector2f direction);
	const int getPoints() const { return pontos; }
	const int getAttackType() const { return attacktype;  }
	const bool getCanJump() const { return canJump; }
	const bool getInvulneravel() const { return invulneravel; }
	const int getLives() const { return lives; }
	void increasePoints(int valor) { pontos += valor; }

};