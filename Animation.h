#pragma once
#include "SFML/Graphics.hpp"
class Animation
{
protected:
	sf::Vector2u imgCount;
	sf::Vector2u imgI;
	float ttotal;
	float stime;
	int frames;
	sf::IntRect uvRect;
	bool lock;
	bool faceright;

public:
	void load (sf::Texture* texture, sf::Vector2u ImgCount, float stime);
	Animation();
	void reset() { imgI = sf::Vector2u(0, 0); }
	void Refresh(float deltat);
	void setLock() { lock = true; }
	const bool getFaceright() const { return faceright; }
	void setFaceright() { faceright = true; }
	const bool getLock() const { return lock; }
	const int getFrame() const { return frames; }
};

