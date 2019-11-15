#include "ButtonLoad.h"

void MenuButtons::ButtonLoad::executar()
{
	// logica de carregar fase
}

MenuButtons::ButtonLoad::ButtonLoad(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getLoad());
}
