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
	void setStime(const float stime) { this->stime = stime; }
	void frameup() { frames++; }
	void reset() { imgI = sf::Vector2u(0, 0); frames = 0; }
	void Refresh(float deltat);
	void setLock() { lock = true; }
	void setImgC(sf::Vector2u imgC) { this->imgCount = imgC; }
	const bool getFaceright() const { return faceright; }
	void setFaceright(const bool opt) { faceright = opt; }
	void setFrame(const int frame) { this->frames = frame; }
	const sf::Vector2u getImgC() const { return imgCount; }
	const sf::IntRect getUV() const { return uvRect; }
	void setUV(const sf::Vector2i size) { uvRect.width = size.x; uvRect.height = size.y; }
	const bool getLock() const { return lock; }
	void setimgI(const sf::Vector2u imgI) { this->imgI = imgI; }
	const sf::Vector2u getimgI() const { return imgI; }
	const int getFrame() const { return frames; }
};

