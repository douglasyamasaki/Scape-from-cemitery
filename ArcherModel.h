#pragma once
#include <SFML/Graphics.hpp>
namespace Models{
	class ArcherModel
	{
	private:
		static ArcherModel* instance;
		sf::Texture* Walk;
		sf::Texture* Idle;
		sf::Texture* JumpUp;
		sf::Texture* JumpDown;
		sf::Texture* Attack01;
		sf::Texture* Attack02;
		sf::Texture* Attack03;
		sf::Texture* Die;
		ArcherModel();
	public:
		~ArcherModel();
		static ArcherModel* getInstance();
		sf::Texture* getWalk() { return Walk; }
		sf::Texture* getIdle() { return Idle; }
		sf::Texture* getJumpDown() { return JumpDown; }
		sf::Texture* getJumpUp() { return JumpUp; }
		sf::Texture* getAttack01() { return Attack01; }
		sf::Texture* getAttack02() { return Attack02; }
		sf::Texture* getAttack03() { return Attack03; }
		sf::Texture* getDie() { return Die; }
	};
}
