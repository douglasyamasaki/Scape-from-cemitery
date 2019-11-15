#include "PauseCommand.h"

void CompController::PauseCommand::executar(sf::Event* e)
{
	MenuPause* pptr = dynamic_cast<MenuPause*>(mref->getCurrentMenu());
	if (pptr != nullptr) {
		pptr->on();
	}
}

