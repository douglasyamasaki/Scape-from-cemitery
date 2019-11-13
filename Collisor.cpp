#include "Collisor.h"

Collisor::Collisor(sf::Vector2f body) : hitbox(body)
{
}

Collisor::Collisor (sf::Vector2f size, sf::Vector2f displacement, sf::Vector2f cmpos) : hitbox (size) {
	hitbox.setOrigin(size/2.0f);
	this->displacement = displacement;
	hitbox.setPosition(cmpos - displacement);
}
bool Collisor::CheckCollision(Collisor* other, sf::Vector2f& direction , float push)
{
	sf::Vector2f otherPos = other->getHBPos();
	sf::Vector2f otherHalfSize = other->getHalfsize();
	sf::Vector2f thisPosition = getHBPos();
	sf::Vector2f thisHalfSize = getHalfsize();

	float deltax = otherPos.x - thisPosition.x;
	float deltay = otherPos.y - thisPosition.y;
	float interX = abs(deltax) - (otherHalfSize.x + thisHalfSize.x);
	float interY = abs(deltay) - (otherHalfSize.y + thisHalfSize.y);
	if (interX < 0.0f && interY < 0.0f) {
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (interX > interY) {
			if (deltax > 0.0f) {
				moveHB(interX * (1.0f - push), 0.0f);
				other->moveHB(-interX * push, 0.0f);
				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else {
				moveHB(-interX * (1.0f - push), 0.0f);
				other->moveHB(interX * push, 0.0f);
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else {
			if (deltay > 0.0f) {
				moveHB(0.0f,interY * (1.0f - push));
				other->moveHB(0.0f, -interY * push);
				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else {
				moveHB(0.0f, -interY * (1.0f - push));
				other->moveHB(0.0f, interY * push);
				direction.x = 0.0f;
				direction.y = -1.0f;
			}

		}
		return true;
	}
	return false;
}
