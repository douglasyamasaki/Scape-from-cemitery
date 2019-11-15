#pragma once
#include "GenericList.h"
#include "StaticEntity.h"
using namespace AbstractEntity;

class StaticList : public GenericList<StaticEntity>
{
private:
public:
	StaticList(){}
	~StaticList();
};

