#include "UpCommand.h"
void CompController::UpCommand::executar(sf::Event* e)
{
	if (pref != nullptr)
		if (pref->getAttackType() == 0)
			pref->jump();
}

