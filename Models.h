#pragma once
#include <SFML/Graphics.hpp>

namespace SpriteModels {
	class ArcherModel {
	private:
		static ArcherModel* instance;
		sf::Texture* Walk;
		sf::Texture* Idle;
		sf::Texture* JumpUp;
		sf::Texture* JumpDown;
		ArcherModel();
	public:
		static ArcherModel* getInstance();
		sf::Texture* getWalk() { return Walk; }
		sf::Texture* getIdle() { return Idle; }
		sf::Texture* getJumpDown() { return JumpDown; }
		sf::Texture* getJumpUp() { return JumpUp; }
	};
}