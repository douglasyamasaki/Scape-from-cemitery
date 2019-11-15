#include "Attack02Command.h"

void CompController::Attack02Command::executar(sf::Event* e)
{
	if (pref != nullptr && !pref->getLock() && pref->getCanJump()) {
		pref->setLock();
		pref->setAttType(2);
		pref->reset();
	}
}
