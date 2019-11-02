#pragma once
#include "GenericList.h"
#include "AbstractEntitys.h"
#include "Arrow.h"
using namespace AbstractEntitys;

namespace Lists {
	class StaticList : public List<StaticEntity> {
	public:
		Iterator it;
	};
	class ArrowList : public List<Arrow> {
	public:
		Iterator it;
	};
}