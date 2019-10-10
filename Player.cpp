#include "Player.h"

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f) {
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
		velocity.x = 0.0f;
	if (direction.y < 0.0f) {
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f) {
		velocity.y = 0.0f;
	}
}

Player::Player(sf::Vector2f size, sf::Vector2f pos, float speed, sf::Vector2f HBArea) : DynamicEntity(size, pos , speed,HBArea)
{
	jumpHeight = 200.0f;
	hitbox.setPosition(pos);
	hitbox.setOrigin(HBArea / 2.0f);
	textures = ArcherModel::getInstance();
	setTexture(textures->getIdle());
	load(textures->getIdle(), sf::Vector2u(6, 4), 0.1);
	this->setOrigin(getSize() / 2.0f);
}


void Player::update(float deltat) {

	velocity.x = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump) {
		canJump = false;
		velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += 981.0f * deltat;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		velocity.x -= speed;
		faceright = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocity.x += speed;
		faceright = true;
	}
	

	if (velocity.x > 0.0f || velocity.x < 0.0f) {
		setTexture(textures->getWalk());
	}
	else{
		setTexture(textures->getIdle());
	}

	Refresh(deltat);
	setTextureRect(uvRect);
	moveHB(velocity.x*deltat, velocity.y*deltat);
	setPosition(hitbox.getPosition() - deslHB);

}
