#pragma once
#include "GenericList.h"
#include "AbstractEntitys.h"
using namespace AbstractEntitys;

namespace Lists {
	class StaticList : public List<StaticEntity> {
	public:
		Iterator it;

	};
}