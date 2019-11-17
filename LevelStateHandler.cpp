#include "LevelStateHandler.h"
#include <fstream>
#include "EnemiesList.h"
#include "StaticList.h"
#include "ProjectileList.h"
using namespace std;
LevelStateHandler::LevelStateHandler()
{
	projetiles = nullptr;
	enemies = nullptr;
	statics = nullptr;
	p1 = nullptr;
	p2 = nullptr;
	leveltype = -1;
}

void LevelStateHandler::save()
{
	ofstream file;
	file.open("level.txt", std::ios_base::app);

	if (projetiles != nullptr && enemies != nullptr && statics != nullptr) {
		file << leveltype << endl;
		file << projetiles->getSize() <<endl;
		file << enemies->getSize() << endl;
		file << statics->getSize()<<endl;
	}
	file.close();
}
