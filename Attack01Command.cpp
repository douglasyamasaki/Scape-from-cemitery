#include "Attack01Command.h"

void CompController::Attack01Command::executar(sf::Event* e)
{
	if (pref != nullptr && !pref->getLock() && pref->getCanJump()) {
		pref->setLock();
		pref->setAttType(1);
		pref->reset();
	}
}

