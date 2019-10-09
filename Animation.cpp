#include "Animation.h"
void Animation::load(sf::Texture* texture, sf::Vector2u ImgCount, float stime)
{
	this->imgCount= ImgCount;
	this->stime = stime;
	frames = 0;
	lock = false;
	faceright = true;
	ttotal = 0;
	imgI.x = 0;
	imgI.y = 0;
	uvRect.width = texture->getSize().x / float(ImgCount.x);
	uvRect.height = texture->getSize().y / float(ImgCount.y);

}



void Animation::Refresh(float deltat)
{
	ttotal += deltat;
	if (ttotal >= stime) {
		ttotal -= stime;
		imgI.x++;
		frames++;
		if (imgI.x >= imgCount.x){
			imgI.x = 0;
			imgI.y++;
			if (imgI.y >= imgCount.y){
				imgI.y = 0;
				frames = 0;
				lock = false;
			}
		}
	}
	
	if (faceright) {
		uvRect.left = imgI.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else{
		uvRect.left = (imgI.x +1 )* abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
	uvRect.top = imgI.y * uvRect.height;
}
