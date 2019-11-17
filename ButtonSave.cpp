#include "ButtonSave.h"
#include "MenuHandler.h"
#include "Principal.h"

void MenuButtons::ButtonSave::executar()
{
	mref->getMhref()->getPrincipal()->save();
}

MenuButtons::ButtonSave::ButtonSave(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : ButtonBase (size,pos,mref)
{
	
	textures->ButtonsModel::getInstance();
	setTexture(textures->getSave());

}
