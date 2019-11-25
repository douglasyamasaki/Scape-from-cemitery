#include "EnterCommand.h"
#include "MenuNaming.h"
#include "MenuHandler.h"

void CompController::EnterCommand::executar(sf::Event* e)
{
	if (mref != nullptr) {
		MenuNaming* menuptr = dynamic_cast<MenuNaming*>(mref->getCurrentMenu());
		if (menuptr != nullptr)
			menuptr->confirm();
		off();
	}
}
