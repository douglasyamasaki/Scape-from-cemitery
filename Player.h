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
	bool dead;
	float jumpHeight;
	int lives;
	int pontos;
	int attacktype;
public:
	const bool getDead() { return dead; }
	void attacktypex(const int index);
	void restartplayer();
	void setDead(const bool opt) { this->dead = opt; }
	void setList(ProjectileList* arrowlistref) { this->arrowlistref = arrowlistref; }
	void setName(string name) { this->name = name; }
	void setAttType(int valor) { attacktype = valor; }
	void attack();
	void updateTexture();
	void OnCollision(sf::Vector2f direction);
	Player(sf::Vector2f pos);
	void update(float deltat);
	sf::RectangleShape getHit() { return hitbox; }
	void jump();
	void moveRight();
	void moveLeft();
	const string getName() const  { return name; }
	void setPos(sf::Vector2f pos);
	void onHit(sf::Vector2f direction);
	const sf::Vector2f getVelocity() const { return velocity; }
	const int getPoints() const { return pontos; }
	const int getAttackType() const { return attacktype;  }
	const bool getCanJump() const { return canJump; }
	const bool getInvulneravel() const { return invulneravel; }
	const int getLives() const { return lives; }
	void increasePoints(int valor) { pontos += valor; }
	void setLives(const int lives) { this->lives = lives; }
	void setInvulneravel() { invulneravel = true; }
	void setVelocity(const sf::Vector2f velocity) { this->velocity = velocity; }
	~Player() { arrowlistref = nullptr; textures = nullptr; }

};