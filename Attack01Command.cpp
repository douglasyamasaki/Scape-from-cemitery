#include "Attack01Command.h"

void CompController::Attack01Command::executar(sf::Event* e)
{
	if (pref != nullptr) {
		pref->attacktypex(1);
	}
}

Attack01Command::~Attack01Command(){}

