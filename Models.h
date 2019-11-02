#pragma once
#include <SFML/Graphics.hpp>

namespace SpriteModels {
	class ArcherModel {
	private:
		static ArcherModel* instance;
		sf::Texture* Walk;
		sf::Texture* Idle;
		sf::Texture* JumpUp;
		sf::Texture* JumpDown;
		sf::Texture* Attack01;
		sf::Texture* Attack02;
		sf::Texture* Attack03;
		ArcherModel();
	public:
		static ArcherModel* getInstance();
		sf::Texture* getWalk() { return Walk; }
		sf::Texture* getIdle() { return Idle; }
		sf::Texture* getJumpDown() { return JumpDown; }
		sf::Texture* getJumpUp() { return JumpUp; }
		sf::Texture* getAttack01() { return Attack01; }
		sf::Texture* getAttack02() { return Attack02; }
		sf::Texture* getAttack03() { return Attack03; }
	};
	class ArrowModel {
	private:
		static ArrowModel* instance;
		sf::Texture* Arrow;
		ArrowModel();
	public:
		static ArrowModel* getInstance();
		sf::Texture* getArrow() { return Arrow; }
	};

	class GhostModel {
	private:
		static GhostModel* instance;
		sf::Texture* Ghost;
		GhostModel();
	public:
		static GhostModel* getInstance();
		sf::Texture* getGhost() { return Ghost; }
	};

	class MenuModel {
	private:
		static MenuModel* instance;
		sf::Texture* Pause;
		sf::Texture* Win;
		sf::Texture* Lose;
		sf::Texture* Selection;
		sf::Texture* Ranking;
		sf::Texture* Main;
		MenuModel();
	public:
		static MenuModel* getInstance();
		sf::Texture* getPause() { return Pause; }
		sf::Texture* getWin() { return Win; }
		sf::Texture* getLose() { return Lose; }
		sf::Texture* getSelection() { return Selection; }
		sf::Texture* getRanking() { return Ranking; }
		sf::Texture* getMain() { return Main; }
	};

	class ButtonModel {
	private:
		static ButtonModel* instance;
		sf::Texture* P1;
		sf::Texture* P2;
		sf::Texture* BossStage;
		sf::Texture* Stage1;
		sf::Texture* Highscore;
		sf::Texture* Load;
		sf::Texture* MainMenu;
		sf::Texture* Quit;
		sf::Texture* Resume;
		sf::Texture* Save;
		ButtonModel();
	public:
		static ButtonModel* getInstance();
		sf::Texture* getP1() { return P1; }
		sf::Texture* getP2() { return P2; }
		sf::Texture* getBossStage() { return BossStage; }
		sf::Texture* getStage1() { return Stage1; }
		sf::Texture* getHighscore() { return Highscore; }
		sf::Texture* getLoad() { return Load; }
		sf::Texture* getMainMenu() { return MainMenu; }
		sf::Texture* getQuit() { return Quit; }
		sf::Texture* getResume() { return Resume; }
		sf::Texture* getSave() { return Save; }
		
	};
}
