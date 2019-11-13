#pragma once
#include "SFML/Graphics.hpp"
class Animation
{
protected:
	sf::Vector2u imgCount;
	sf::Vector2u imgI;
	float totalt;
	float stime;
	int frames;
	sf::IntRect uvRect;
	bool lock;
	bool faceright;

public:
	void load (sf::Texture* texture, sf::Vector2u ImgCount, float stime);
	Animation();
	void setStime(const float stime) { this->stime = stime; }
	void frameup() { frames++; }
	void reset() { imgI = sf::Vector2u(0, 0); frames = 0; }
	void Refresh(float deltat);
	void setLock() { lock = true; }
	void setImgC(sf::Vector2u imgC) { this->imgCount = imgC; }
	const bool getFaceright() const { return faceright; }
	void setFaceright() { faceright = true; }
	const bool getLock() const { return lock; }
	const int getFrame() const { return frames; }
};

