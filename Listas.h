#pragma once
#include "GenericList.h"
#include "AbstractEntitys.h"
#include "Arrow.h"
#include "Inimigo.h"
using namespace AbstractEntitys;

namespace Lists {
	class StaticList : public List<StaticEntity> {
	public:
	};
	class ArrowList : public List<Arrow> {
	public:
	};

	class EnemieList : public List<Inimigo> {
	public:
	};
}