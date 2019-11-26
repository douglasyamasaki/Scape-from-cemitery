#pragma once
#include <SFML/Graphics.hpp>
class TilesetModel
{
private:
	sf::Texture* Tile1;
	sf::Texture* Background;
	static TilesetModel* instance;
	TilesetModel();
public:
	sf::Texture* getTile1  () const { return Tile1; }
	sf::Texture* getBackground() const { return Background; }
	static TilesetModel* getInstance();
};

