#pragma once
#include "MenuBase.h"
#include <vector>
using namespace std;
namespace Menus {
	class MenuRanking : public MenuBase {
		class RankingSlot {
		private:
			string name;
			int pontos;
		public:
			RankingSlot() { pontos = 0; name = ""; }
			const string getName() const { return name; }
			const int getInt() const { return pontos; }
			void setPontos(const int pontos) { this->pontos = pontos; }
			void setString(sf::String string) { name = string; }
		};
	protected:
		sf::Font font;
		vector<RankingSlot*> rankings;
		void sortRankings();
	public:
		void reset();
		void read();
		MenuRanking(sf::Vector2f size, MenuHandler* MHref);
		~MenuRanking(){delete(bmm);}
		void executar(sf::Event* event);
	};
}
