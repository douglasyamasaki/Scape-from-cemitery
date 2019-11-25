#include "Player.h"
#include "Arrow.h"


void Player::updateTexture()
{
	if (!getLock()) {
		if (velocity.y > 0.0f && !canJump)
			setTexture(textures->getJumpUp());
		else if (velocity.y < 0.0f)
			setTexture(textures->getJumpDown());
		else if ((velocity.x > 0.0f || velocity.x < 0.0f) && !getLock())
			setTexture(textures->getWalk());
		else if (velocity.x == 0.0f && !getLock())
			setTexture(textures->getIdle());
	}
}

void Player::OnCollision(sf::Vector2f direction)
{
	
	if (direction.x < 0.0f) {
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
		velocity.x = 0.0f;
	if (direction.y < 0.0f) {
		invulneravel = false;
		setFillColor(sf::Color::White);
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f) {
		velocity.y = 0.0f;
	}
}


Player::Player(sf::Vector2f pos) : DynamicEntity (sf::Vector2f(250, 200),pos, sf::Vector2f(125, 0), sf::Vector2f(101, 131), sf::Vector2f(15, -20))
{
	attacktype = 0;
	this->deslocamento = deslocamento;
	jumpHeight = 200.0f;
	textures = ArcherModel::getInstance();
	setTexture(textures->getIdle());
	load(textures->getIdle(), sf::Vector2u(6, 4), 0.1);
	this->setOrigin(getSize() / 2.0f);
	this->arrowlistref = nullptr;
	pontos = 2000;
	lives = 5;
	name = "";
	invulneravel = false;

}

void Player::update(float deltat) {
	if (!invulneravel)
		velocity.x = movdirection.x * speed.x;
	updateTexture();
	Refresh(deltat);
	setTextureRect(uvRect);
	moveHB(velocity.x*deltat, velocity.y*deltat);
	if (!faceright)
		setPosition(hitbox.getPosition().x-deslocamento.x , hitbox.getPosition().y + deslocamento.y);
	else
		setPosition(hitbox.getPosition().x + deslocamento.x, hitbox.getPosition().y + deslocamento.y);
	if (!invulneravel)
		movdirection.x = 0;
	velocity.y += 981.0f * deltat;
	attack();
}

void Player::jump()
{
	if (canJump) {
		canJump = false;
		velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
	}

}

void Player::moveRight()
{
	if (!getLock()){
		movdirection.x = 1;
		faceright = true;
	}
}

void Player::moveLeft()
{
	if (!getLock()){
	movdirection.x = -1;
	faceright = false;
	}
}

void Player::setPos(sf::Vector2f pos)
{
	hitbox.setPosition(pos);
	if (!faceright)
		setPosition(hitbox.getPosition().x - deslocamento.x, hitbox.getPosition().y + deslocamento.y);
	else
		setPosition(hitbox.getPosition().x + deslocamento.x, hitbox.getPosition().y + deslocamento.y);
}

void Player::onHit(sf::Vector2f direction)
{
	if (!invulneravel){
	velocity.x = -direction.x * 2*speed.x;
	velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
	canJump = false;
	invulneravel = true;
	lives--;
	setFillColor(sf::Color::Red);
	}
}

void Player::attacktypex(const int index)
{
	if (canJump && !lock) {
		setLock();
		setAttType(index);
		reset();
	}
}

void Player::attack() {
	if (attacktype == 0)
		return;
	if (attacktype == 1){
		setTexture(textures->getAttack01());
		setStime(0.05);
	}
	if (attacktype == 2)
		setTexture(textures->getAttack02());
	if (attacktype == 3)
		setTexture(textures->getAttack03());
	if (attacktype > 0 ) {
		setStime(0.05);
		if (!getLock()){
			attacktype = 0;
			setStime(0.05);
		}
		if (getFrame() == 8 && attacktype == 1) {
			Arrow* aux = new Arrow(getPosition()+sf::Vector2f(0,30), sf::Vector2f(1000,-350), this);
			*arrowlistref + aux;
			if (!faceright) {
				aux->scale(-1, 1);
				aux->flip();

			}
			frameup();
		}
		if (getFrame() == 10 && attacktype == 2) {
			for (int i = 0; i < 3; i++) {
				int k = rand() % 240;
				Arrow* aux = new Arrow(getPosition() + sf::Vector2f(0, 30), sf::Vector2f(800-k,-350+k),this);
				*arrowlistref + aux;
				if (!faceright) {
					aux->scale(-1, 1);
					aux->flip();

				}
				frameup();
			}
		}
		if (getFrame() == 10 && attacktype == 3) {
			for (int i=0; i<5 ; i++){
				int k = rand() % 240;
				int j = rand() % 50;
				Arrow* aux = new Arrow(getPosition() + sf::Vector2f(0, 30), sf::Vector2f(320-j,-900+k), this);
				*arrowlistref + aux;
				if (!faceright) {
					aux->scale(-1, 1);
					aux->flip();

				}
				frameup();
		}
		}
		
	}
}