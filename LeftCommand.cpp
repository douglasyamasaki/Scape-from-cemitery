#include "LeftCommand.h"

void CompController::LeftCommand::executar(sf::Event* e)
{
	if (pref != nullptr) 
		pref->moveLeft();
}
