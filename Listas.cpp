#include "Listas.h"
#include "Spell.h"

void Lists::ProjectileList::manageSpells()
{
	for (it = this->getFirst(); it.getIt() != nullptr; it++) {
		Spell* spellptr = dynamic_cast<Spell*>(it.getIt()->getInfo());
		if (spellptr != nullptr) {
			if (!spellptr->getActive())
				remove();
		}
	}
}
