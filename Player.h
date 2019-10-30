#pragma once
#include "Models.h"
#include "Animation.h"
#include "AbstractEntitys.h"
using namespace SpriteModels;
using namespace AbstractEntitys;

class Player : public DynamicEntity, Animation {
private:
	ArcherModel* textures;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
	sf::Vector2f deslocamento;
public:
	void updateTexture();
	void OnCollision(sf::Vector2f direction);
	Player(sf::Vector2f size, sf::Vector2f pos, float speed, sf::Vector2f HBArea);
	Player(sf::Vector2f size, sf::Vector2f pos, float speed, sf::Vector2f hitbox, sf::Vector2f deslocamento);
	void update(float deltat);
	sf::RectangleShape getHit() { return hitbox; }
	void jump();
	void moveRight();
	void moveLeft();

};