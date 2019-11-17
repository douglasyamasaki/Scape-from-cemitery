#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include "EventHandler.h"
#include "MenuHandler.h"
#include "FirstLevel.h"
#include "Level.h"
#include "SecondLevel.h"
using namespace std;
static const float VIEW_HEIGHT = 720.0f;
static const float VIEW_WIDTH = 1280.0f;

class Principal
{
private:
	EventHandler controle;
	sf::RenderWindow window;
	sf::Clock clock;
	float deltat;
	void ResizeView(const sf::RenderWindow& window, sf::View& view);
	sf::View view;

	//menu
	MenuHandler mh;

	//Players propriamentes dito
	Player* p1;
	Player* p2;
	bool hasp2; // controla a presenca de um p2 na fase
	//Fases
	Level* levelref; // fase de controle
	int leveltype; // refere a de cima
	FirstLevel first;
	//SecondLevel second;
public:
	sf::RenderWindow* getWindow() { return &window; }
	Principal();
	~Principal();
	void setP2on(const bool opt) { hasp2 = opt; }
	const bool getHasP2() const { return hasp2; }
	void startDefaultLevel(int index); // inicia um nivel (index seria qual nivel) via default
	void resetView() { window.setView(window.getDefaultView()); }
	void manageLevel(); //gerencia os menus e eventos que se desencadeiam caso o jogador(es) vencam/percam
	void executar();
	void load(); // carrega as informacoes basicas para dai carregar o nivel
	void save(); // inicia o processo de save
	void clearcurrentlevel();//reseta o nivel atual para o estado inicial
	void setName(const int index, const string name); //seta o nome de p1 ou p2
};

