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
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f) {
		velocity.y = 0.0f;
	}
}


Player::Player(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f speed, sf::Vector2f hitbox, sf::Vector2f deslocamento, ArrowList* ref) : DynamicEntity (size,pos,speed,hitbox,deslocamento)
{
	attacktype = 0;
	this->deslocamento = deslocamento;
	jumpHeight = 200.0f;
	textures = ArcherModel::getInstance();
	setTexture(textures->getIdle());
	load(textures->getIdle(), sf::Vector2u(6, 4), 0.1);
	this->setOrigin(getSize() / 2.0f);
	this->arrowlistref = ref;
	pontos = 0;
	lives = 10;

}

void Player::update(float deltat) {

	velocity.y += 981.0f * deltat;
	updateTexture();
	Refresh(deltat);
	setTextureRect(uvRect);
	moveHB(velocity.x*deltat, velocity.y*deltat);
	if (!faceright)
		setPosition(hitbox.getPosition().x-deslocamento.x , hitbox.getPosition().y + deslocamento.y);
	else
		setPosition(hitbox.getPosition().x + deslocamento.x, hitbox.getPosition().y + deslocamento.y);
	velocity.x = 0.0f;
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
	velocity.x += speed.x;
	faceright = true;
	}
}

void Player::moveLeft()
{
	if (!getLock()){
	velocity.x -= speed.x;
	faceright = false;
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
			setStime(0.1);
		}
		if (getFrame() == 8 && attacktype == 1) {
			Arrow* aux = new Arrow(sf::Vector2f(120, 15), getPosition()+sf::Vector2f(0,30), sf::Vector2f(1000,-350), sf::Vector2f(100, 50), sf::Vector2f(0, 0),this);
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
				Arrow* aux = new Arrow(sf::Vector2f(120, 15), getPosition() + sf::Vector2f(0, 30), sf::Vector2f(800-k,-350+k), sf::Vector2f(100, 50), sf::Vector2f(0, 0),this);
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
				Arrow* aux = new Arrow(sf::Vector2f(120, 15), getPosition() + sf::Vector2f(0, 30), sf::Vector2f(320-j,-900+k), sf::Vector2f(100, 50), sf::Vector2f(0, 0),this);
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