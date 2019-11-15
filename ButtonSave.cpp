#include "ButtonSave.h"

void MenuButtons::ButtonSave::executar()
{
}

MenuButtons::ButtonSave::ButtonSave(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase (size,pos,mref)
{
	textures->ButtonsModel::getInstance();
	setTexture(textures->getSave());
}
