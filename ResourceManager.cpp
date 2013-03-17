#include "ResourceManager.h"

#include <algorithm>

#include "SDL/SDL_image.h"

ResourceManager::ResourceManager()
{
	mAnimations["enemy"] = std::shared_ptr<SpriteAnimation>(new SpriteAnimation("enemy_anim.png", 32, 32));
}

ResourceManager::ResourceManager(std::string atlusFileName )
{
}

std::shared_ptr<SpriteAnimation> ResourceManager::getAnimationResource( std::string resourceName ) 
{
	if( mAnimations.find(resourceName) != mAnimations.end() )
		return mAnimations[resourceName];

	return NULL;
}