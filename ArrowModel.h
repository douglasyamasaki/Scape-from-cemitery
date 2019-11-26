#pragma once
#include <SFML/Graphics.hpp>
namespace Models{
class ArrowModel
{
	private:
		static ArrowModel* instance;
		sf::Texture* Arrow;
		ArrowModel();
	public:
		~ArrowModel();
		static ArrowModel* getInstance();
		sf::Texture* getArrow() { return Arrow; }
	};
}

