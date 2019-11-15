#include "MenuClickCommand.h"

void CompController::MenuClickCommand::executar(sf::Event* e)
{
	active = false;
	if (mref != nullptr)
		if (mref->getActive())
			mref->input(sf::Vector2f(e->mouseButton.x, e->mouseButton.y));
}
