#include "Body.h"

Body::Body(sf::Vector2f body) : hitbox(body)
{
}

Body::Body (sf::Vector2f size, sf::Vector2f deslocamento, sf::Vector2f cmpos) : hitbox (size) {
	hitbox.setOrigin(size/2.0f);
	this->deslocamento = deslocamento;
	hitbox.setPosition(cmpos - deslocamento);
}
