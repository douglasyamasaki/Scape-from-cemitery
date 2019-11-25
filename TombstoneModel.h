#pragma once
#include <SFML/Graphics.hpp>
namespace Models {
class TombstoneModel
{
private:
	static TombstoneModel* instance;
	sf::Texture* Tombstone;
	TombstoneModel();
public:
	~TombstoneModel();
	static TombstoneModel* getInstance();
	sf::Texture* getTombstone() const { return Tombstone; }
};
}
