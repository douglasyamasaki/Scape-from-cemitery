#pragma once
#include "Level.h"
class FirstLevel : public Level
{
private:
public:
	FirstLevel();
	void check_collision();
	void load_static();
	void load_default();
	void update(float deltat);
};
