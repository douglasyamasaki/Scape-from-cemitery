#pragma once
#include "Models.h"
#include "Animation.h"
#include "AbstractEntitys.h"
#include "Listas.h"
using namespace Lists;
using namespace SpriteModels;
using namespace AbstractEntitys;

class Player : public DynamicEntity, public Animation {
private:
	ArrowList* arrowlistref;
	ArcherModel* textures;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
	int lives;
	int pontos;
	int attacktype;
public:
	void setAttType(int valor) { attacktype = valor; }
	void attack();
	void updateTexture();
	void OnCollision(sf::Vector2f direction);
	Player(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f HBArea);
	Player(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento, ArrowList* ref);
	void update(float deltat);
	sf::RectangleShape getHit() { return hitbox; }
	void jump();
	void moveRight();
	void moveLeft();
	void increasePoints(int valor) { pontos += valor; }

};