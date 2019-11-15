#include "RightCommand.h"

void CompController::RightCommand::executar(sf::Event* e)
{
	if (pref != nullptr) 
		pref->moveRight();
}
