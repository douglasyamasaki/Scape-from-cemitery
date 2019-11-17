#include "Attack03Command.h"

void CompController::Attack03Command::executar(sf::Event* e)
{
	if (pref != nullptr) {
		pref->attacktypex(3);
	}
}
