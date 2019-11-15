#pragma once
#include <SFML/Graphics.hpp>

namespace Models{
	class WarlockModel
	{
	private:
		static WarlockModel* instance;
		sf::Texture* Walk;
		sf::Texture* Rise;
		sf::Texture* Idle;
		sf::Texture* Die;
		sf::Texture* Cast1;
		sf::Texture* Cast2;
		sf::Texture* Cast3;
		WarlockModel();
	public:
		static WarlockModel* getInstance();
		sf::Texture* getWalk() { return Walk; }
		sf::Texture* getRise() { return Rise; }
		sf::Texture* getIdle() { return Idle; }
		sf::Texture* getDie() { return Die; }
		sf::Texture* getCast1() { return Cast1; }
		sf::Texture* getCast2() { return Cast2; }
		sf::Texture* getCast3() { return Cast3; }
	};
}

