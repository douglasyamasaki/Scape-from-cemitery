#pragma once
#include <SFML/Graphics.hpp>
namespace Models {
	class SpikeModel
	{
	private:
		static SpikeModel* instance;
		sf::Texture* Spike;
		SpikeModel();
	public:
		static SpikeModel* getInstance();
		sf::Texture* getSpike() { return Spike; }
	};
}