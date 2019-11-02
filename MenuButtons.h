#pragma once
#include "MenuButtonBase.h"
namespace MenuButtons {
	class Button1p : public MenuButtonBase {
	private:
	public:
		void executar();
		Button1p(sf::Vector2f size, sf::Vector2f pos, Menu* ref);
	};
	class Button2p : public MenuButtonBase {
	private:
	public:
		void executar();
		Button2p(sf::Vector2f size, sf::Vector2f pos, Menu* ref);
	};
	class ButtonBossStage : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonBossStage(sf::Vector2f size, sf::Vector2f pos, Menu* ref);
	};
	class ButtonHighscore : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonHighscore(sf::Vector2f size, sf::Vector2f pos, Menu* ref);
	};
	class ButtonLoad : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonLoad(sf::Vector2f size, sf::Vector2f pos, Menu* ref);
	};
	class ButtonMainMenu : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonMainMenu(sf::Vector2f size, sf::Vector2f pos, Menu* ref);
	};
	class ButtonQuit : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonQuit(sf::Vector2f size, sf::Vector2f pos, Menu* ref);
	};
	class ButtonResume : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonResume(sf::Vector2f size, sf::Vector2f pos, Menu* ref);
	};
	class ButtonStage1 : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonStage1(sf::Vector2f size, sf::Vector2f pos, Menu* ref);
	};
	class ButtonSave : public MenuButtonBase {
	private:
	public:
		void executar();
		ButtonSave(sf::Vector2f size, sf::Vector2f pos, Menu* ref);
	};
}
