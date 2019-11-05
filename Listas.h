#pragma once
#include "GenericList.h"
#include "AbstractEntitys.h"
#include "Arrow.h"
#include "Inimigo.h"
using namespace AbstractEntitys;
class Projectile;
namespace Lists {
	class StaticList : public List<StaticEntity> {
	public:
	};


	class ProjectileList : public List<Projectile> {

	};

	class EnemieList : public List<Inimigo> {
	public:
	};
}