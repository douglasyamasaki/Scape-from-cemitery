#pragma once
#include "Controller.h"
namespace CompController{
class MenuClickCommand : public Controller
{
private:
public:
	MenuClickCommand() : Controller() { active = true; }
	~MenuClickCommand(){active = false;}
	void setMenuHandler(MenuHandler* mhref) { this->mref = mhref; }
	void executar(sf::Event* e);
};
}

