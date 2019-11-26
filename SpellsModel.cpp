#include "SpellsModel.h"
using namespace Models;

SpellsModel* SpellsModel::instance = 0;

SpellsModel::SpellsModel()
{
	Spell1 = new sf::Texture;
	Spell2 = new sf::Texture;
	Spell3 = new sf::Texture;
	Spell1->loadFromFile("./Sprites/Warlock/Spell01.png");
	Spell2->loadFromFile("./Sprites/Warlock/Spell02.png");
	Spell3->loadFromFile("./Sprites/Warlock/Spell03.png");
}
SpellsModel::~SpellsModel()
{
	delete(Spell1);
	delete(Spell2);
	delete(Spell3);
	delete(instance);
}

SpellsModel* SpellsModel::getInstance()
{
	if (!instance)
		instance = new SpellsModel();
	return instance;
}
