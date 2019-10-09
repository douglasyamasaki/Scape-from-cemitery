#include "Models.h"
using namespace SpriteModels;

class TextureManager
{
private:
	ArcherModel* ArcherInstance;
	static TextureManager* instance;
	TextureManager();
public:
	ArcherModel* getArcherInstance() const { return ArcherInstance; }
	static TextureManager* getManager();

};
