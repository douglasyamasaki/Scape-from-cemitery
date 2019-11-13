#pragma once
#include "GenericList.h"
#include "AbstractEntitys.h"
#include "Inimigo.h"
#include "Projectile.h"
using namespace AbstractEntitys;

namespace Lists {
	class StaticList : public List<StaticEntity> {
	public:

	};


	class ProjectileList : public List<Projectile> {
	public:
		void manageSpells();
	};

	class EnemieList : public List<Inimigo> {
	public:
	};
}