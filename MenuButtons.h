#pragma once
#include "MenuButtonBase.h"
namespace MenuButtons {
	class Button1p : public MenuButtonBase {
	private:
	public:
		void executar();
		Button1p(sf::Vector2f size, sf::Vector2f pos, Menu* mref);
	};
	class Button2p : public MenuButtonBase {
	private:
	public:
		void executar();
		Button2p(sf::Vector2f size, sf::Vector2f pos, Menu* mref);
	};
	class ButtonBossStage : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonBossStage(sf::Vector2f size, sf::Vector2f pos, Menu* mref);
	};
	class ButtonHighscore : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonHighscore(sf::Vector2f size, sf::Vector2f pos, Menu* mref);
	};
	class ButtonLoad : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonLoad(sf::Vector2f size, sf::Vector2f pos, Menu* mref);
	};
	class ButtonMainMenu : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonMainMenu(sf::Vector2f size, sf::Vector2f pos, Menu* mref);
	};
	class ButtonQuit : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonQuit(sf::Vector2f size, sf::Vector2f pos, Menu* mref);
	};
	class ButtonResume : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonResume(sf::Vector2f size, sf::Vector2f pos, Menu* mref);
	};
	class ButtonStage1 : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonStage1(sf::Vector2f size, sf::Vector2f pos, Menu* mref);
	};
	class ButtonSave : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonSave(sf::Vector2f size, sf::Vector2f pos, Menu* mref);
	};
}
