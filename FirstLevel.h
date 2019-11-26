#pragma once
#include "Level.h"
class FirstLevel : public Level
{
private:
	void resetlists();
public:
	FirstLevel();
	void check_collision();
	void load_static();
	void load_default();
	void update(float deltat);
	void setFinished();
};
