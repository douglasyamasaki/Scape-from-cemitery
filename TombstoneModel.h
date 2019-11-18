#pragma once
#include <SFML/Graphics.hpp>
namespace Models {
class TombstoneModel
{
private:
	static TombstoneModel* instance;
	sf::Texture* Tombstone1;
	sf::Texture* Tombstone2;
	TombstoneModel();
public:
	~TombstoneModel();
	static TombstoneModel* getInstance();
	sf::Texture* getTombstone1() const { return Tombstone1; }
	sf::Texture* getTombstone2() const { return Tombstone2; }
};
}
