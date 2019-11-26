#pragma once
#include <SFML/Graphics.hpp>
namespace Models {
	class MineModel
	{
	private:
		static MineModel* instance;
		sf::Texture* Mine;
		MineModel();
	public:
		~MineModel();
		static MineModel* getInstance();
		sf::Texture* getMine() { return Mine; }
	};
}

