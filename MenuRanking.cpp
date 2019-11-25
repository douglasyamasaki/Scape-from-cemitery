#include "MenuRanking.h"
#include "ButtonMainMenu.h"
#include "MenuHandler.h"
#include "Principal.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
using namespace MenuButtons;

void Menus::MenuRanking::sortRankings()
{
	int n = rankings.size();
	int key;
	int i,j;
	for (i = 1; i < n; i++) {
		RankingSlot* key = rankings[i];
		j = i - 1;

		while (j >= 0 && rankings[j]->getInt() < key->getInt()) {
			rankings[j + 1] = rankings[j];
			j--;
		}
		rankings[j + 1] = key;


	}
}

void Menus::MenuRanking::reset()
{
	rankings.clear();
}

void Menus::MenuRanking::read()
{
	ifstream file("ranking.txt");
	string line;
	if (file.is_open()) {
		while (!(file.eof())) {
			line.clear();
			RankingSlot* aux = new RankingSlot;
			getline(file, line);
			aux->setString(line);
			if (line.size() == 0)
				continue;
			line.clear();
			getline(file, line);
			const char* c = line.c_str();
			aux->setPontos(atoi(c));
			rankings.push_back(aux);
		}
		file.close();
	}
	font.loadFromFile("./Font/ranking.ttf");
	sortRankings();
}

Menus::MenuRanking::MenuRanking(sf::Vector2f size, MenuHandler* MHref) : MenuBase(size, MHref)
{
	setTexture(texture->getRanking());
	ButtonMainMenu* bmm = new ButtonMainMenu(sf::Vector2f(244, 57), sf::Vector2f(525, 625), this);
	add(bmm);
}

void Menus::MenuRanking::executar(sf::Event* event)
{
	drawMenu();
	sf::Text text;
	string line;
	text.setFont(font);
	text.setCharacterSize(25);
	vector<RankingSlot*>::iterator it;
	int i = 1;
	for (it = rankings.begin(); it != rankings.end(); it++) {
		char buffer[64];
		text.setPosition(sf::Vector2f(150, 135 + 30 * (i-1)));
		_itoa_s(i, buffer, 64, 10);
		line += buffer;
		line += ". ";
		line += rankings[i-1]->getName();
		text.setString(line);
		this->getMhref()->getPrincipal()->getWindow()->draw(text);
		line.clear();
		text.setPosition(sf::Vector2f(825, 135 + 30 * (i-1)));
		_itoa_s(rankings[i - 1]->getInt(), buffer, 64, 10);
		line += buffer;
		text.setString(line);
		this->getMhref()->getPrincipal()->getWindow()->draw(text);
		i++;
		line.clear();
		if (i > 15)
			break; //somente os top 15 do arquivo ranking serao imprimidos
	}
}
