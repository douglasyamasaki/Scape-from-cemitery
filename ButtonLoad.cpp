#include "ButtonLoad.h"
#include "Principal.h"

void MenuButtons::ButtonLoad::executar()
{
	mref->getMhref()->getPrincipal()->load();
}

MenuButtons::ButtonLoad::ButtonLoad(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase(size, pos, mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getLoad());
}
