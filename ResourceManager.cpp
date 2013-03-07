#include "ResourceManager.h"

#include <algorithm>

#include "SDL/SDL_image.h"

#include "ImageLoadException.h"
#include "Texture.h"

ResourceManager::ResourceManager() :
	mResources()
{
}

std::shared_ptr<Resource> ResourceManager::getResource( int handle )
{
	return NULL;
}

int ResourceManager::loadTexture( std::string filename )
{
	return 0;
}