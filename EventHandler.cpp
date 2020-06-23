#include "EventHandler.h"

EventHandler::EventHandler(MenuHandler* mhref)
{
		this->mhref = mhref;
		p1up = sf::Keyboard::Key::W;
		p1left = sf::Keyboard::Key::A;
		p1right = sf::Keyboard::Key::D;
		p1attack01 = sf::Keyboard::Key::X;
		p1attack03 = sf::Keyboard::Key::V;
		p1attack02 = sf::Keyboard::Key::C;

		p2up = sf::Keyboard::Key::I;
		p2left = sf::Keyboard::Key::J;
		p2right = sf::Keyboard::Key::L;
		p2attack01 = sf::Keyboard::Key::B;
		p2attack03 = sf::Keyboard::Key::N;
		p2attack02 = sf::Keyboard::Key::M;

		pause = sf::Keyboard::Key::P;
		enter = sf::Keyboard::Key::Enter;
		ecmd.setMenuHandler(mhref);
		mclick.setMenuHandler(mhref);
		pcommand.setMenuHandler(mhref);
		click = static_cast<sf::Keyboard::Key>(999);
		controllers.add(enter, &ecmd);
		controllers.add(pause, &pcommand);
		controllers.add(click, &mclick);

}

void EventHandler::setP1(Player* p1)
{
	// adiciona os controles como arvore
	CompositeController* p1c = new CompositeController();
	p1c->add(p1up, new UpCommand());
	p1c->add(p1left, new LeftCommand());
	p1c->add(p1right, new RightCommand());
	CompositeController* p1a = new CompositeController();
	p1a->add(p1attack01, new Attack01Command());
	p1a->add(p1attack02, new Attack02Command());
	p1a->add(p1attack03, new Attack03Command());
	p1c->setRef(p1);
	p1a->setRef(p1);
	p1c->add(sf::Keyboard::Key::Unknown, p1a);
	controllers.add(sf::Keyboard::Key::Unknown, p1c);
}

void EventHandler::setP2(Player* p2)
{
	// adiciona os controles como arvore
	CompositeController* p2c = new CompositeController();
	p2c->add(p2up, new UpCommand());
	p2c->add(p2left, new LeftCommand());
	p2c->add(p2right, new RightCommand());
	CompositeController* p2a = new CompositeController();
	p2a->add(p2attack01, new Attack01Command());
	p2a->add(p2attack02, new Attack02Command());
	p2a->add(p2attack03, new Attack03Command());
	p2c->setRef(p2);
	p2a->setRef(p2);
	p2c->add(sf::Keyboard::Key::Unknown, p2a);
	controllers.add(static_cast<sf::Keyboard::Key>(-2), p2c);
}
void EventHandler::restartcontrollers()
{
	controllers.clearcomposite();
	controllers.add(enter, &ecmd);
	controllers.add(pause, &pcommand);
	controllers.add(click, &mclick);
}
void EventHandler::update(sf::Event* ev)
{
	controllers.executar(ev);
}
