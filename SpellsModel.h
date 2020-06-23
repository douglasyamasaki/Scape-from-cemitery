#pragma once
#include <SFML/Graphics.hpp>

namespace Models{
class SpellsModel
{
	private:
		static SpellsModel* instance;
		sf::Texture* Spell1;
		sf::Texture* Spell2;
		sf::Texture* Spell3;
		SpellsModel();
	public:
		static SpellsModel* getInstance();
		sf::Texture* getSpell1() { return Spell1; }
		sf::Texture* getSpell2() { return Spell2; }
		sf::Texture* getSpell3() { return Spell3; }
};
}
