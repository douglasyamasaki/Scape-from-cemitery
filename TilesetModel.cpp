#include "TilesetModel.h"

TilesetModel* TilesetModel::instance = 0;

TilesetModel::TilesetModel()
{
	Tile1 = new sf::Texture;
	Background = new sf::Texture;
	Tile1->loadFromFile("./Sprites/Tileset/Tile1.png");
	Background->loadFromFile("./Sprites/Tileset/Background.png");
}

TilesetModel* TilesetModel::getInstance()
{
	if (instance == nullptr)
		instance = new TilesetModel;
	return instance;
}
