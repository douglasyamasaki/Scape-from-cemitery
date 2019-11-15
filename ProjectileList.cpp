#include "ProjectileList.h"
#include "Spell.h"

void ProjectileList::ManageSpells()
{
	for (it = this->getPrimeiro(); it.getIt() != nullptr; it++) {
		Spell* spellptr = dynamic_cast<Spell*>(it.getIt()->getInfo());
		if (spellptr != nullptr) {
			if (!spellptr->getActive())
				remove();
		}
	}
}

ProjectileList::~ProjectileList()
{
	clean();
}
