#include "Attack03Command.h"

void CompController::Attack03Command::executar(sf::Event* e)
{
	if (pref != nullptr && !pref->getLock() && pref->getCanJump()) {
		pref->setLock();
		pref->setAttType(3);
		pref->reset();
	}
}