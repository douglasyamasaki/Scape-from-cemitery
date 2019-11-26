#pragma once
#include "Entity.h"
#include "ButtonsModel.h"
#include "MenuBase.h"
using namespace AbstractEntity;
using namespace Models;

	class ButtonBase : public Entity
	{
	protected:
		ButtonsModel* textures;
		MenuBase* mref;
	public:
		ButtonBase(sf::Vector2f size, sf::Vector2f pos, MenuBase* mref) : Entity(size) { this->mref = mref; textures = ButtonsModel::getInstance(); setPosition(pos); }
		~ButtonBase(){delete(instance)}
		virtual void executar() = 0;
	};



