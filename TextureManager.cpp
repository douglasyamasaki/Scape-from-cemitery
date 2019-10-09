#include "TextureManager.h"

TextureManager* TextureManager::instance = 0;

TextureManager::TextureManager()
{
	ArcherInstance = ArcherModel::getInstance();
}

TextureManager* TextureManager::getManager()
{
	if (!instance)
		instance = new TextureManager();
	return instance;
}
