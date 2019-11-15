#pragma once
#include "Enemie.h"
#include "GenericList.h"
using namespace AbstractEntity;
class EnemiesList : public GenericList<Enemie>
{
public:
	EnemiesList(){}
	~EnemiesList();
};

