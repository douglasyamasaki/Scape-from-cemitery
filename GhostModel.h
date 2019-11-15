#pragma once
#include <SFML/Graphics.hpp>
namespace Models{
class GhostModel
{
private:
	static GhostModel* instance;
	sf::Texture* Ghost;
	GhostModel();
public:
	static GhostModel* getInstance();
	sf::Texture* getGhost() { return Ghost; }
};
}

