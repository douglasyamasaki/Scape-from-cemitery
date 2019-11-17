#include "Attack02Command.h"

void CompController::Attack02Command::executar(sf::Event* e)
{
	if (pref != nullptr) {
		pref->attacktypex(2);
	}
}
