#pragma once
#include "Projectile.h"
#include "GenericList.h"
using namespace AbstractEntity;
class ProjectileList : public GenericList<Projectile>
{
public:
	ProjectileList(){}
	void ManageSpells();
	~ProjectileList();
};

