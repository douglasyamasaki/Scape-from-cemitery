#pragma once
#include "Principal.h"
#include "Level.h"
#include "Player.h"
#include "Plataform.h"
#include 






class LevelFactory
{
protected:
	
	virtual void load();

	Principal* pGame;
	bool toLoad;
	bool twoPlayers;

	short idLevel;

	Player* p1;
	Player* p2;

	Level* level;
	vector<Plataform*> plataforms;

public:
	LevelFactory(Principal* game = NULL);
	virtual ~LevelFactory();

	virtual Level* criar() = 0;

	void clear();

	//sets and gets
	void setLoad(const bool l) { 
		toLoad = l;
	}
	void setTwoPlayers(const bool two) { 
		twoPlayers = two;
	}
	void setPlayers(Player* player1, Player* player2);
};